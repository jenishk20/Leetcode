class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int mini=1e9;
        for(auto i:strs)
        {
            int k=i.size();
            mini=min(mini,k);
            
        }
        for(int i=mini;i>=1;i--)
        {
            set<string>se;
            for(auto it:strs)
            {
                se.insert(it.substr(0,i));
            }
            // cout<<i<<" ";
            // for(auto it:se)
            //     cout<<it<<" ";
            // cout<<endl;
            if(se.size()==1)
                return *se.begin();
                
        }
        return "";
    }
};