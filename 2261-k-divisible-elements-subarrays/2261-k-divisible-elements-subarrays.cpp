class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>>ans;
        int i,j;
        for(i=0;i<n;i++)
        {
            vector<int>temp;
            int ct=0;
            for(j=i;j<n;j++)
            {
                if(nums[j]%p==0)
                    ct++;
                if(ct>k)
                    break;
                temp.push_back(nums[j]);
                
                
                ans.insert(temp);
            }
            
        }
        
        return ans.size();
    }
};