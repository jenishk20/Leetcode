class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        
        int n=groupSizes.size();
        int i;
        map<int,vector<int>>ma;
        for(i=0;i<n;i++)
        {
            ma[groupSizes[i]].push_back(i);
        }
        for(auto i:ma)
        {
            auto it=i.second.begin();
            while(it!=i.second.end())
            {
                vector<int>temp;
                copy(it,it+i.first,back_inserter(temp));
                it+=i.first;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};