class Solution {
public:
    int dp[101][101][201];
    bool recur(int i,int j,int k,string &s1,string &s2,string &s3)
    {
        if(k==s3.size()){
            
            return i==s1.size() and j==s2.size();
        }
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(i<s1.size() and s1[i]==s3[k])
        {
            if(j<s2.size() and s2[j]==s3[k])
            {
                bool op1=recur(i+1,j,k+1,s1,s2,s3);
                bool op2=recur(i,j+1,k+1,s1,s2,s3);
                return dp[i][j][k]=op1 or op2;
            }
            return dp[i][j][k]=recur(i+1,j,k+1,s1,s2,s3);
        }
        if(j<s2.size() and s2[j]==s3[k])
            return dp[i][j][k]=recur(i,j+1,k+1,s1,s2,s3);
        
        return 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof dp);
        return recur(0,0,0,s1,s2,s3);
    }
};