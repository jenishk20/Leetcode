class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            if(nums[left]==target or nums[right]==target)
                return true;
            else if(nums[left]<target)
            {
                while(left<right and nums[left+1]==nums[left] )
                left++;
                
                left++;
            }
            else if(target<nums[right])
            {
                while(left<right and nums[right-1]==nums[right])
                    right--;
                right--;
            }
            else
                break;
        }
        return false;
    }
};