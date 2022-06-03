class Solution {
public:
    int find(string s)
    {
        map<char,int>ma;
        for(auto it:s)
            ma[it]++;
        
        auto it=*ma.begin();
        return it.second;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int>temp;
        vector<int>ans;
        
        for(auto i:words)
            temp.push_back(find(i));
        sort(temp.begin(),temp.end());
        for(auto it:temp)
            cout<<it<<" ";
        cout<<endl;
        int n=words.size();
        for(auto i:queries)
        {
            int k=find(i);
            
            auto it=upper_bound(temp.begin(),temp.end(),k)-temp.begin();
            
            ans.push_back(n-it);
        }
        return ans;
    }
};