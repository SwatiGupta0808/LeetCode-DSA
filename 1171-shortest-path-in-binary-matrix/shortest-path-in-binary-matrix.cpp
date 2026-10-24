class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=1;

        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<int> dr={1,-1,0,0,-1,-1,1,1};
        vector<int> dc={0,0,1,-1,-1,1,1,-1};

        while(!q.empty())
        {
            auto it=q.front();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            if(r==n-1 && c==m-1)
                return dis;
            for(int i=0;i<8;i++)
            {
                int row=r+dr[i];
                int col=c+dc[i];
                if(row>=0 && row<n && col>=0 &&col<m && grid[row][col]==0 && dist[row][col]> dis+1)
                {
                    dist[row][col]=dis+1;
                    q.push({dis+1,{row,col}});
                }
            }
        }
        return -1;
    }
};