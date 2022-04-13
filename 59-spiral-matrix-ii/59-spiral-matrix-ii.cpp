class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        
        
        int dir=0;
        int curr=1;
        int r1=0,r2=n-1,c1=0,c2=n-1;
        while(r1<=r2 and c1<=c2)
        {
            
            //Left to Right
            for(int i=c1;i<=c2;i++)
                ans[r1][i]=curr++;

            //Top To Down
            for(int i=r1+1;i<=r2;i++)
                ans[i][c2]=curr++;
            
            //Right to Left
            for(int i=c2-1;i>c1;i--)
                ans[r2][i]=curr++;
            
            //Down to Up 
            for(int i=r2;i>r1;i--)
                ans[i][c1]=curr++;
            
            r1++;
            r2--;
            c1++;
            c2--;
                
        }
        return ans;
        
        
      
    }
};