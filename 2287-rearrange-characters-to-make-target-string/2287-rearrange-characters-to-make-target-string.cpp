class Solution {
public:
    int rearrangeCharacters(string s, string target) {
         map<char,int>ma,ma1;
        
        for(auto i:s)
            ma[i]++;
        
        for(auto i:target)
            ma1[i]++;
        int kk=1e8;
        set<char>se;
        for(auto i:target)
            se.insert(i);
        
        for(auto i:se)
        {
            int have=ma[i];
            int req=ma1[i];
            
            if(have==0)
                return 0;
            
            int can_make=have/req;
            kk=min(kk,can_make);
        }

        return kk;
        
    }
};