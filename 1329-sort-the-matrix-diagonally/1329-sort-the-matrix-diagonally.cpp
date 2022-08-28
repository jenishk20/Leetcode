class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,priority_queue<int,vector<int>,greater<int>>>ma;
        
        int n=mat.size();
        int m=mat[0].size();
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<i<<" "<<j<<" "<<i-j<<endl;
                ma[i-j].push(mat[i][j]);
            }
        }
        vector<vector<int>>ans(n,vector<int>(m));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ans[i][j]=ma[i-j].top();
                ma[i-j].pop();
            }
        }
        return ans;
    }
};