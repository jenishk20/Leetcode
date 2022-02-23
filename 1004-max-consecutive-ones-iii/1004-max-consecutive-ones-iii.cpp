class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int zeroes=0,ones=0;
        
        int st=0,en=0;
        int n=nums.size();
        int ans=0;
        for(;en<n;en++)
        {
            if(!nums[en])
                zeroes++;
            while(zeroes>k and st<en)
            {
                
                if(nums[st]==0)
                zeroes--;
                st++;
            }
            
            if(zeroes<=k)
                ans=max(ans,en-st+1);
            
        }
        return ans;
    }
};