class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 ||i==n-1 ||j==m-1) && board[i][j]=='O')
                {
                    q.push({i,j});
                    board[i][j]='#';
                }
            }
        }

        vector<int> a={1,-1,0,0};
        vector<int> b={0,0,-1,1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=row+a[i];
                int nc=col+b[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O')
                {
                    board[nr][nc]='#';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='#')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        
    }
};