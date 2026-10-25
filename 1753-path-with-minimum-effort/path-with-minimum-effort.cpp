class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,1,-1};

        while(!pq.empty())
        {
            auto it=pq.top();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();

            if(r==n-1 && c==m-1)
                return diff;
            for(int i=0;i<4;i++)
            {
                int row=r+dr[i];
                int col=c+dc[i];
                if(row>=0 && col>=0 && row<n && col<m)
                {
                    int ne=max(abs(heights[r][c]-heights[row][col]),diff);
                    if(ne<dist[row][col])
                    {
                        dist[row][col]=ne;
                        pq.push({ne,{row,col}});
                    }
                }
            }
        }
        return 0;

        
    }
};