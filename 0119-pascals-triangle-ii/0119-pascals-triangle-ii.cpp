class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans(rowIndex+1);
        int i ;
        for(i=0;i<=rowIndex;i++){
            
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            
            for(int j=1;j<i;j++){   
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
        for(auto i:ans){
    
            for(auto it:i)
                cout<<it<<" ";
            cout<<endl;
        }
        return ans[rowIndex];
    }
};