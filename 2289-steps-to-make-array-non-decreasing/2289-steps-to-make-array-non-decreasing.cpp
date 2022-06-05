class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>se;
        int n=nums.size();
        se.push({nums[n-1],0});
        int ans=0;
        int i;
        for(i=n-2;i>=0;i--)
        {
            int cnt=0;
            while(!se.empty() and nums[i]>se.top().first)
            {
                cnt=max(cnt+1,se.top().second);
                se.pop();
            }
            ans=max(ans,cnt);
            se.push({nums[i],cnt});
        }
        return ans;
    }
};