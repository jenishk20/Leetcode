class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int>ans;
        int n=nums.size();
        int oddSum=0,evenSum=0;
        for(auto i:nums)
        {
            if(i&1)
                oddSum+=i;
            else
                evenSum+=i;
        }
        for(auto i:queries)
        {
            int idx=i[1];
            int val=i[0];
            
            if(nums[idx]&1)
            {
                if(val&1)
                {
                    evenSum+=nums[idx]+val;
                    oddSum-=nums[idx];
                    
                }
                else
                {
                    oddSum+=val;
                }
            }
            else
            {
                if(val&1)
                {
                    evenSum-=nums[idx];
                    oddSum+=nums[idx]+val;
                    
                }
                else
                {
                    evenSum+=val;
                }
            }
            nums[idx]+=val;
            
            cout<<idx<<" "<<val<<" "<<oddSum<<" "<<evenSum<<endl;
            ans.push_back(evenSum);
        }
        return ans;
    }
};