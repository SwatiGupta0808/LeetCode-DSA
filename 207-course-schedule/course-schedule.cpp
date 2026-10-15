class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj,vector<int> &visited,vector<int> &previs)
    {
        visited[node]=1;
        previs[node]=1;

        for(auto adjNode:adj[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode,adj,visited,previs))
                    return true;
            }
            else if(previs[adjNode]==1)
                return true;
        }
        previs[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(numCourses,0);
        vector<int> previs(numCourses,0);

        for(int i=0;i<numCourses;i++)
        {
            if(dfs(i,adj,visited,previs))
                return false;
        }
        return true;
    }
};