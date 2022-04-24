class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        
        vector<int>st,en;
        for(auto i:flowers)
        {
            st.push_back(i[0]);
            en.push_back(i[1]);
        }
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());
       
        vector<int>ans;
        for(auto i:persons)
        {
            auto it=upper_bound(st.begin(),st.end(),i)-st.begin();
            auto it2=lower_bound(en.begin(),en.end(),i)-en.begin();
           // cout<<it<<" "<<it2<<endl;
            ans.push_back(it-it2);
        }
        return ans;
            
    }
};