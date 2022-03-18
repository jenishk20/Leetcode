class Solution {
public:
    int recur(int idx,vector<int>&coins,int amount,
             vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            return ((amount%coins[idx])==0);
        }
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];
        int notTake=recur(idx-1,coins,amount,dp);
        int take=0;
        if(coins[idx]<=amount)
            take=recur(idx,coins,amount-coins[idx],dp);
        return dp[idx][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return recur(n-1,coins,amount,dp);
    }
};