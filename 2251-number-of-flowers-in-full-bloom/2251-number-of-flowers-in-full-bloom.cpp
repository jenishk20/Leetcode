class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int,int>ma;
        
        for(auto i:flowers)
        {
            ma[i[0]]++;
            ma[i[1]+1]--;
        }
        
        int sum=0;
        for(auto &i:ma)
        {
            sum+=i.second;
            i.second=sum;
        }
       
        // for(auto i:ma)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        vector<int>ans(persons.size(),0);
        for(int i=0;i<persons.size();i++)
        {
            auto it=ma.upper_bound(persons[i]);
            if(it!=ma.begin())
            {
                it--;
                ans[i]=it->second;
            }
        }
        
        return ans;
    }
};