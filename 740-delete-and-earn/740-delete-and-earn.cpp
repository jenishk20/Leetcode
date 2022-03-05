class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(2e4+1,0);
        map<int,int>ma;
        int mx=*max_element(nums.begin(),nums.end());
        for(auto i:nums)
            ma[i]++;
        
        dp[1]=ma[1];
        dp[2]=max(dp[1],ma[2]*2);
        int i;
        for(i=3;i<=mx;i++)
        {
            dp[i]=max(dp[i-1],i*ma[i]+dp[i-2]);
        }
        return dp[mx];
    }
};