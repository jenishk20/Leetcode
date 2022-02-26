class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int len=INT_MAX;
        int i=0,j=0;
        long long sum=0;
        
        while(j<n)
        {
            sum+=nums[j];
            if(sum>=target)
            {
                cout<<i<<" "<<j<<endl;
                while(sum-nums[i]>=target)
                {
                    if(sum-nums[i]>=target)
                    sum-=nums[i];
                    i++;
                }
                cout<<i<<endl;
                len=min(len,j-i+1);
            }
            j++;
        }
        return len==INT_MAX?0:len;
       
    }
};