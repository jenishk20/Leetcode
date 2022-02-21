class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int i,j;
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int k=min(rowSum[i],colSum[j]);
                ans[i][j]=k;
                rowSum[i]-=k;
                colSum[j]-=k;
            }
        }
        return ans;
    }
};