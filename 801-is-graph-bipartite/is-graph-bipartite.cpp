class Solution {
public:
    bool check(int start,vector<vector<int>> graph,vector<int> &colour)
    {
        queue<int> q;
        q.push(start);
        colour[start]=1;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto adjNode: graph[node])
            {
                if(colour[adjNode]==-1)
                {
                    colour[adjNode]=!colour[node];
                    q.push(adjNode);
                }
                else if(colour[adjNode]==colour[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> colour(v,-1);
        for(int i=0;i<v;i++)
        {
            if(colour[i]==-1)
            {
                if(check(i,graph,colour)==false)
                    return false;
            }
        }
        return true;
    }
};