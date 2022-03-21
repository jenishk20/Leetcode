class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int req=nums.size()/2;
        map<int,int>ma;
        for(auto i:nums)
            ma[i]++;
        for(auto i:ma)
        {
            if(i.second&1)
                return false;
            req-=(i.second/2);
        }
        return req==0;
    }
};