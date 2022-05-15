class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string s=to_string(num);
        int n=s.size();
        int c=0;
        int i;
        for(i=0;i<=n-k;i++)
        {
            //cout<<s.substr(i,k)<<endl;
            string tt=s.substr(i,k);
            
            int ans=stoi(tt);
            if(ans==0)
                continue;
            if(num%ans==0)
                c++;
        }
        return c;
    }
};