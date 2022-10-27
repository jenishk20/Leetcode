class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>ma;
        int sum=0;
        int i;
        ma[0]=-1;
        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(ma.find(sum%k)==ma.end())
                ma[sum%k]=i;
            else
            {
                int j=ma[sum%k];
                
                //cout<<j<<endl;
                if(i-j>=2)
                    return 1;
            }
            
        }
        return 0;
    }
};