class Solution {
public:
    void dfs(vector<list<int>> &graph,unordered_set<int> &visited, unordered_set<int> &recStack,int source)
    {
        visited.insert(source);
        for(int node : graph[source])
        {
            if(visited.find(node) == visited.end())
                dfs(graph,visited,recStack,node))
                
        }
        recStack.insert(source);
     }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        vector<list<int>> graph(numCourses);
        
        for(vector<int> pre : prerequisites)
        {
            graph[pre[0]].push_back(pre[1]);
        }
        unordered_set<int> visited;
        unordered_set<int> recStack;
       for(vector<int> pre : prerequisites)
        {
            dfs(graph,visited,recStack,pre[0]);
        }
        
           
    }
};