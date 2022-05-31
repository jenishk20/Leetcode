class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        set<string>se;
        int i=0;
        int n=s.size();
        for(i=0;i<=n-k;i++)
        {
          //  cout<<i<<endl;
            se.insert(s.substr(i,k));
        }
        
        int t=se.size();
        int req=pow(2,k);
        return t==req;
    }
};