class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans;
        vector<int>vis(n+1,0);
        sort(nums.begin(),nums.end());
        int missing=-1,doubled=-1;
        bool be=false;
       
        for(int i=0;i<n;i++)
        {
            if(vis[nums[i]])
                doubled=nums[i];
            vis[nums[i]]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i+1])
                missing=i+1;
        }
        ans.push_back(doubled);
        ans.push_back(missing);
        return ans;
    }
};