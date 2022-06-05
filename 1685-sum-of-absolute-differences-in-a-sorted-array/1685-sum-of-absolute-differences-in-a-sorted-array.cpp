class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n=nums.size();
        int i,j;
        vector<int>pfx(n,0),sfx(n,0);
        pfx[0]=0;
        for(i=1;i<n;i++)
        {
            pfx[i]+=pfx[i-1]+nums[i-1];
        }
        sfx[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            sfx[i]+=sfx[i+1]+nums[i+1];
        }
        vector<int>ans(n,0);
        for(i=0;i<n;i++)
        {
            int frontEle=i;
            int backEle=n-i-1;
            
            ans[i]+=(frontEle*nums[i]-pfx[i]);
            ans[i]+=(sfx[i]-backEle*nums[i]);
        }
        return ans;
    }
};