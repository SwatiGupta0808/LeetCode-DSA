class Solution {
public:
    bool dfs(int node, int target,vector<int> &visited, vector<vector<int>> &adj)
    {
        if(node==target)
            return true;
        
        visited[node]=1;
        for(auto adjNode:adj[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode, target, visited, adj))
                    return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n= edges.size();
        vector<vector<int>> adj(n+1);

        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            vector<int> visited(n+1,0);

            //check if the edge exist already
            if(dfs(u,v, visited, adj))
                return edge;
            
            //if not exist, add the edge in adjecency list
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};