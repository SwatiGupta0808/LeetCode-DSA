class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        //stop, destination, cost
        q.push({0,{src,0}});

        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;

            if(k<stop) continue;

            for(auto adjNode:adj[node])
            {
                int newNode=adjNode.first;
                int newCost=adjNode.second;

                if(dist[newNode]>newCost+cost)
                {
                    dist[newNode]=newCost+cost;
                    q.push({stop+1,{newNode, newCost+cost}});
                }
            }
        }
        if(dist[dst]==INT_MAX)
            return -1;
        else return dist[dst];
        
    }
};