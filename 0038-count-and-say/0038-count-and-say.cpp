class Solution {
public:
    string countAndSay(int n) {
        
        if(n==0) return "";
        
        if(n==1)
            return "1";
        
        int i;
        string res="1";
        while(--n)
        {
            string curr="";
            for(i=0;i<res.size();i++)
            {
                int cnt=1;
                char ch=res[i];
                while(i+1<res.size() and res[i+1]==ch)
                {
                    i++;
                    cnt++;
                }
                curr+=(to_string(cnt))+res[i];
                
            }
           // cout<<curr<<endl;
            res=curr;
        }
        return res;
    }
    
};