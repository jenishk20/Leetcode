class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            
            
            while(low<high and nums[low]==nums[low+1])
                low++;
            while(low<high and nums[high]==nums[high-1])
                high--;
            int mid=(low+high)/2;
            
            if(nums[mid]==target)
                return true;
            if(nums[mid]>=nums[low])
            {
                if(target>=nums[low] and target<=nums[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(target>=nums[mid] and target<=nums[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return false;
    }
};