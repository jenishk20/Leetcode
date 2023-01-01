class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        
        vector<string>v;
        stringstream iss(s);
        string word;
        while(iss>>word)
            v.push_back(word);
        

        set<string>st;
        
        if(pattern.size()!=v.size()) return false;
        
        map<char,string>ma;
        int i;
        for(i=0;i<pattern.size();i++)
        {
            char ch=pattern[i];
            if(ma.find(ch)!=ma.end())
            {
               
                if(ma[ch]!=v[i])
                    return false;
            }
            else
            {
               
                if(st.count(v[i])>0)
                    return false;
                
                ma[ch]=v[i];
                st.insert(v[i]);
            }
            
        }
        return true;
    }
};
