class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        
        int i,j;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>prev(m+1,0),curr(m+1,0);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    curr[j]=1+prev[j-1];
                else
                    curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
        
    }
};