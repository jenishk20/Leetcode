class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        while(1)
        {
            if(nums.size()==1)
                break;
            vector<int>tt;
            for(int i=0;i<nums.size()-1;i++)
                tt.push_back((nums[i]+nums[i+1])%10);
            
            nums=tt;
        }
        return nums[0];
    }
};