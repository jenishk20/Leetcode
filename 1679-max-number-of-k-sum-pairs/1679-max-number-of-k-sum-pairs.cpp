class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int j=n-1;
        int ans=0;
        while(i<j)
        {
            if(nums[i]+nums[j]==k)
            {
                ans++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]>k)
            {
                j--;
            }
            else
                i++;
        }
        return ans;
    }
};