class Solution {
public:
    static bool comp(string &s,string &t)
    {
        return s.size()<t.size();
    }
    bool check(string &s,string &t)
    {
        int n=s.size();
        int m=t.size();
        
        if(n+1!=m)
            return false;
        int i=0;
        for(auto ch:t)
        {
            if(i==n)
                return 1;
            if(ch==s[i])
                i++;
        }
        return i==n;
    }
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        int i,j;
        int maxi=1;
        // for(auto i:words)
        //     cout<<i<<" ";
        // cout<<endl;
        vector<int>dp(n+1,1);
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
               if(check(words[j],words[i]) and dp[i]<dp[j]+1)
               {
                   dp[i]=dp[j]+1;
               }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};