class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n);
        
        int i;
        stack<int>se;
        for(i=n-1;i>=0;i--)
        {
            if(se.empty())
            {
                ans[i]=prices[i];
            }
            else if(se.top()<=prices[i])
            {
                ans[i]=prices[i]-se.top();
            }
            else
            {
                while(!se.empty() and prices[i]<se.top())
                    se.pop();
                if(se.empty())
                ans[i]=prices[i];
                else
                    ans[i]=prices[i]-se.top();
            }
            se.push(prices[i]);
        }
        return ans;
        
    }
};