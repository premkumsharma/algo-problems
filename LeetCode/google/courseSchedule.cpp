/*
Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
*/

class Solution {
public:
    bool isCyclic(vector<list<int>> &graph,unordered_set<int> &visited, unordered_set<int> &recStack,int source)
    {
        if(recStack.find(source) != recStack.end()) return true;
        recStack.insert(source);
        visited.insert(source);
        for(int node : graph[source])
        {
            if(visited.find(node) == visited.end() && isCyclic(graph,visited,recStack,node))
                return true;
            else if(recStack.find(node) != recStack.end()) return true;
        }
        recStack.erase(source);
        return false;
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
            if(isCyclic(graph,visited,recStack,pre[0]))
                return false;
        }
       return true; 
    }
};