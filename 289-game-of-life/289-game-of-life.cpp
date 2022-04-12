class Solution {
public:
      int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int getNeighbours(int r,int c,vector<vector<int>>&board)
    {
        int neigh=0;
        for(int i=0;i<8;i++)
        {
           int nx=r+dx[i];
            int ny=c+dy[i];
            if(nx>=0 and ny>=0 and nx<board.size() and ny<board[0].size())
            {
                if(abs(board[nx][ny])==1)
                    neigh++;
            }
        }
        return  neigh;
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int nbgh=getNeighbours(i,j,board);
               // cout<<nbgh<<endl;
                if(board[i][j]==0 and nbgh==3)
                {
                    board[i][j]=2;
                }
                else if(board[i][j]==1 and (nbgh<2 or nbgh>3))
                {
                    board[i][j]=-1;
                }
                    
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
               board[i][j]=board[i][j]>0?1:0;
            }
        }
    }
};