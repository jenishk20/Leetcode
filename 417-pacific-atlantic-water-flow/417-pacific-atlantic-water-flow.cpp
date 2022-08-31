class Solution {
private:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int n,m;
    vector<vector<bool>>atlantic,pacific;
public:
    
    void dfs(int x,int y,vector<vector<int>>&heights,
            vector<vector<bool>>&vis)
    {
        //cout<<x<<" "<<y<<" "<<prevHeight<<endl;
        //cout<<x<<" "<<y<<endl;
        if(vis[x][y])
            return;
        vis[x][y]=1;
        
        for(int k=0;k<4;k++)
        {
            int nx=dx[k]+x;
            int ny=dy[k]+y;
            if(nx>=0 and ny>=0 
              and nx<n and ny<m and 
              heights[nx][ny]>=heights[x][y])
            {
                // cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<endl;
                dfs(nx,ny,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        
        n=heights.size();
        m=heights[0].size();
        
        atlantic=pacific=vector<vector<bool>>(n,vector<bool>(m,0));
        
        int i,j;
        for(i=0;i<m;i++)
        {
            
            dfs(0,i,heights,pacific);
            
            dfs(n-1,i,heights,atlantic);
        }
        for(i=0;i<n;i++)
        {
           
            dfs(i,0,heights,pacific);
            
            dfs(i,m-1,heights,atlantic);
        }
        
        
        vector<vector<int>>ans;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(pacific[i][j] and atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};