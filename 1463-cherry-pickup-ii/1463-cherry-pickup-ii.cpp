class Solution {
public:
    int recur(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid,
             vector<vector<vector<int>>>&dp)
    {
        if(j1<0 or j2<0 or j1>=c or j2>=c)
            return -1e8;
        
        if(i==r-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        int maxi=-1e8;
        for(int dx=-1;dx<=1;dx++)
        {
            for(int dy=-1;dy<=1;dy++)
            {
                int value=0;
                if(j1==j2)
                    value+=grid[i][j1];
                else
                    value+=grid[i][j1]+grid[i][j2];
                
                value+=recur(i+1,dx+j1,dy+j2,r,c,grid,dp);
                maxi=max(maxi,value);
            }
            
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        
        int i,j1,j2;
        for(j1=0;j1<c;j1++)
        {
            for(j2=0;j2<c;j2++)
            {
                if(j1==j2)
                    dp[r-1][j1][j2]=grid[r-1][j1];
                else
                    dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
            }
        }
        
        for(i=r-2;i>=0;i--)
        {
            for(j1=0;j1<c;j1++)
            {
                for(j2=0;j2<c;j2++)
                {
                   
                     int maxi=-1e8;
                    for(int dx=-1;dx<=1;dx++)
                    {
                        for(int dy=-1;dy<=1;dy++)
                        {
                            int value=0;
                            if(j1==j2)
                            {
                                value=grid[i][j1];
                            }
                            else
                                value+=grid[i][j1]+grid[i][j2];
                            if(j1+dx>=0 and j2+dy>=0 and j1+dx<c and j2+dy<c)
                            value+=dp[i+1][j1+dx][j2+dy];
                            else
                            value+=(-1e8);
                            maxi=max(maxi,value);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][c-1];
        // return recur(0,0,c-1,r,c,grid,dp);
        
    }
};