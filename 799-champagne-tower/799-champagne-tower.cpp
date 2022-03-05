class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>matrix(200,vector<double>(200,0));
        
        int i,j;
        matrix[0][0]=poured;
        cout<<fixed<<setprecision(11);
        for(i=0;i<=100;i++)
        {
            //cout<<i<<endl;
            for(j=0;j<=i;j++)
            {
                if(matrix[i][j]>=1)
                {
                  matrix[i+1][j]+=(matrix[i][j]-1)/2.0;
                  matrix[i+1][j+1]+=(matrix[i][j]-1)/2.0;
                  matrix[i][j]=1;
                }
                
               
            }
        
        }
        
        return matrix[query_row][query_glass];
    }
};