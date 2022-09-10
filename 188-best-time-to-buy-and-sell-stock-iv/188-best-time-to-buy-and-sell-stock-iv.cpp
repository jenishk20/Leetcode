class Solution {
public:
    int dp[1001][2][101];
    int recur(int idx,bool hold,int k,vector<int>&prices)
    {
        if(idx==prices.size() or k<=0)
            return 0;
        
        if(dp[idx][hold][k]!=-1)
            return dp[idx][hold][k];
        if(hold)
        {
            int op1=prices[idx]+recur(idx+1,!hold,k-1,prices);
            int op2=recur(idx+1,hold,k,prices);
            
            return dp[idx][hold][k]=max(op1,op2);
        }
        else
        {
            // hold=0
            int op1= -prices[idx]+recur(idx+1,!hold,k,prices);
            int op2=recur(idx+1,hold,k,prices);
            
            return dp[idx][hold][k]=max(op1,op2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return recur(0,0,k,prices);
    }
};