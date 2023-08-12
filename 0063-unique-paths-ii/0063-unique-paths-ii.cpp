class Solution {
public:
    int dp[101][101];
    int recur(int i,int j,int n,int m, vector<vector<int>>&grid)
    {
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==0)
        {
            if(i==n-1 and j==m-1)
                return 1;
            if(dp[i][j]!=-1) return dp[i][j];
            int op1 = recur(i+1,j,n,m,grid);
            int op2 = recur(i,j+1,n,m,grid);
            return dp[i][j]= op1 + op2;
        }
        return 0;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof dp);
        return recur(0,0,n,m,grid);
        
    }
};