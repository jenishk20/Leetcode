class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<pair<int,int>>ve;
        int n=nums.size();
        int i,j;
        for(i=0;i<n;i++)
        {
            for(auto j:nums[i])
            {
                ve.push_back({j,i});
            }
        }
        sort(ve.begin(),ve.end());
        // for(auto i:ve)
        //     cout<<i.first<<" "<<i.second<<endl;
        
        vector<int>ans;
        map<int,int>seen;
        int total=0;
        int req=n;
        int st=0;
        for(i=0;i<ve.size();i++)
        {
            int element=ve[i].first;
            int group=ve[i].second;
            
            seen[group]++;
            if(seen[group]==1)
            {
                total++;
            }
            if(total==req)
            {
                while(seen[ve[st].second]>1)
                {
                    seen[ve[st++].second]--;
                }
                if(ans.empty() or ans[1]-ans[0]>ve[i].first-ve[st].first)
                {
                    ans=vector<int>{ve[st].first,ve[i].first};
                }
            }
        }
        return ans;
    }
};