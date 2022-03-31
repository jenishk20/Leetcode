class Solution {
public:
    bool canMake(int sumThreshold,int m,vector<int>&nums)
    {
        int sum=0;
        int subArrays=1;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]<=sumThreshold)
                sum+=nums[i];
            else
            {
                subArrays++;
                sum=nums[i];
            }
        }
        return subArrays<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        
        int low=0;
        int high=0;
        int ans=0;
        for(auto i:nums){
            high+=i;
            low=max(low,i);
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(canMake(mid,m,nums))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        
    }
};