class Solution {
private:
    int dp[1001][2001];
public:
    int recur(vector<vector<int>>&piles,int k,int idx)
    {
        if(idx>=piles.size())
            return 0;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        //Dont Take from current pile
        int op1=recur(piles,k,idx+1);
        int op2=0;
        int maxi=0,sum=0;
        
        maxi=max(maxi,op1);
        //Take from current pile
        for(int i=0;i<piles[idx].size();i++)
        {
            sum+=piles[idx][i];
            if(k-(i+1)>=0)
            {
                op2=sum+recur(piles,k-i-1,idx+1);
                maxi=max(maxi,sum+recur(piles,k-i-1,idx+1));
            }
        }
        return dp[idx][k]=maxi;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof dp);
        return recur(piles,k,0);
    }
};