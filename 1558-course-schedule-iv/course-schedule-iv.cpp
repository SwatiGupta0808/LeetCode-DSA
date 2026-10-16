class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //first create adjecency list and indegree
        vector<vector<int>> adj(numCourses);
        int n=numCourses;
        vector<int> indegree(n,0);

        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<vector<bool>> reachability(n,vector<bool>(n,false));
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:adj[u])
            {
                reachability[u][v]=true;
                for(int i=0;i<n;i++)
                {
                    if(reachability[i][u])
                        reachability[i][v]=true;
                }
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }

        }
        vector<bool> ans;
        for(auto it: queries)
        {
            int u=it[0];
            int v=it[1];
            ans.push_back(reachability[u][v]);
        }
        return ans;

    }
};