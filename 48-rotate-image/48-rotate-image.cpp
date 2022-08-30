class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int i,j;
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                
                int t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
                
        }
      
        for(i=0;i<n;i++)
        {
           reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};