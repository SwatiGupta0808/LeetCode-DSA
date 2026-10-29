class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>> pq;
        pq.push({0,0});      //distance, node
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n,0);

        dist[0]=0;
        ways[0]=1;

        const long long MOD = 1000000007;

        while(!pq.empty())
        {
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it : adj[node])
            {
                int newnode=it.first;
                long long wt=it.second;
                if(dist[newnode]>dis+wt)
                {
                    dist[newnode]=dis+wt;
                    ways[newnode]=ways[node];
                    pq.push({dis+wt, newnode});
                }
                else if(dist[newnode]==dis+wt)
                {
                    ways[newnode]=(ways[newnode]+ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];

    }
};
