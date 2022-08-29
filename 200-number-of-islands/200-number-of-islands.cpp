class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size() and grid[nx][ny]=='1' and !vis[nx][ny])
            {
                dfs(nx,ny,grid,vis);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int i,j;
        int c=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !vis[i][j])
                {
                    c++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return c;
    }
};