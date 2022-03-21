class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        
        
        string p1="",p2="";
        p1+=pattern[0];
        p1+=text;
        p2+=text;
        p2+=pattern[1];
        
        
        
        long long  c1=0,c2=0,ans=0,ans1=0;
        int i;
        if(pattern[0]==pattern[1])
        {
            for(i=0;i<p1.size();i++)
            {
                if(p1[i]==pattern[0])
                    c1++;
            }
            ans=max(ans,(c1*(c1-1))/2);
            c1=0;
            for(i=0;i<p2.size();i++)
            {
                if(p2[i]==pattern[0])
                    c1++;
            }
            ans=max(ans,(c1*(c1-1))/2);
            
            return ans;
        }
        for(i=0;i<p1.size();i++)
        {
            if(p1[i]==pattern[0])
            {
                c1++;
            }
            else if(p1[i]==pattern[1])
            {
                ans+=c1;
            }
        }
        
        for(i=0;i<p2.size();i++)
        {
            if(p2[i]==pattern[0])
            {
                c2++;
            }
            else if(p2[i]==pattern[1])
            {
                ans1+=c2;
            }
        }
        return max(ans,ans1);
    }
};