class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,int>ma;
        int n=nums.size();
        int i;
        for(i=0;i<n;i++)
        {
            if(ma.find(nums[i])!=ma.end())
            {
                if(abs(i-ma[nums[i]])<=k)
                    return  true;
            }
            ma[nums[i]]=i;
        }
        return  false;
    }
};