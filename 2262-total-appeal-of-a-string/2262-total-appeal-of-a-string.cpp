class Solution {
public:
    long long appealSum(string s) {
            
        int n=s.size();
        vector<long long>dp(n,0);
        dp[0]=1;
        map<char,int>ma;
        
        ma[s[0]]=1;
        for(int i=1;i<n;i++)
        {
            dp[i] =dp[i-1]+(i+1-ma[s[i]]);
            ma[s[i]]=i+1;
        }
        return accumulate(dp.begin(),dp.end(),0ll);
    }
};