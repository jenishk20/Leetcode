class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums)
            pq.push(i);

        while(k--)
        {
            int curr=pq.top();
            pq.pop();
            curr++;
            pq.push(curr);
        }
        long long prod=1;
        long long mod=1e9+7;
        while(!pq.empty())
        {
            prod=(prod*1ll*pq.top())%mod;
            pq.pop();
        }
        return prod;
    }
};