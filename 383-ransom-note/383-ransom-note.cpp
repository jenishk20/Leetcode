class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        
        map<char,int>have,req;
        for(auto i:magazine)
            have[i]++;
        
        for(auto i:ransomNote)
            req[i]++;
        
        for(auto i:req)
        {
            if(i.second>have[i.first])
            {
                return false;
            }
        }
        return true;
    }
};