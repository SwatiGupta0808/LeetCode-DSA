class Solution {
public:
    bool dfs(int node, vector<vector<int>> adj, vector<int> &visited, stack<int> &st,vector<int> &pathVisited)
    {
        visited[node]=1;
        pathVisited[node]=1;

        for(auto adjNode:adj[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode,adj,visited,st,pathVisited))
                    return true;
            }
            else if(pathVisited[adjNode]==1)
                    return true;
            
        }
        pathVisited[node]=0;
        st.push(node);
        return false;
    }
    vector<int> topological(vector<vector<int>> adj,int n)
    {
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited, st,pathVisited))
                    return {};
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto edge: prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ans=topological(adj,numCourses);
        return ans; 
    }
};