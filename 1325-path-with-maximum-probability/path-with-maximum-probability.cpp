class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            double u=edges[i][0];
            double v=edges[i][1];
            double wt=succProb[i];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<double, double>> q;
        vector<double> prob(n,INT_MIN);
        prob[start_node]=1;
        q.push({start_node,1});

        while(!q.empty())
        {
            int node=q.top().first;
            double wt=q.top().second;
            q.pop();

            for(auto it: adj[node])
            {
                double u=it.first;
                double pro=it.second;
                if(prob[u]<pro*wt){
                    prob[u]=pro*wt;
                    q.push({u,prob[u]});
                }

            }
        }
        if(prob[end_node]==INT_MIN)
            return 0;
        else 
            return prob[end_node];
    }
};