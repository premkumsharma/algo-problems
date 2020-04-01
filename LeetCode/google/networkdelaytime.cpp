/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
*/

class Solution {
public:
    void dfs(unordered_map<int,list<pair<int,int>>>& graph,vector<int>&dist, int node, int timeSpent)
    {
        if(timeSpent >= dist[node]) return;
        
        dist[node] = timeSpent;
        auto edges = graph.find(node);
        if( edges != graph.end())
        for(pair<int,int> edge : edges->second)
        {
            dfs(graph,dist,edge.first,timeSpent + edge.second);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,list<pair<int,int>>> graph;
        vector<int> distance(N+1,INT_MAX);
        for(vector<int> edge : times)
        {
            graph[edge[0]].push_back(make_pair(edge[1],edge[2]));
        }
        
        
        dfs(graph,distance,K,0);
        
        int maxTime = 0;
        for(int i = 1 ; i <=N ; i++)
        {
             maxTime = max(maxTime,distance[i]);
        if(maxTime == INT_MAX) return -1;
            
        } return maxTime;
        
    }
};