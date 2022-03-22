class Solution {
public:
    string getSmallestString(int n, int k) {
       
        
        string res="";
        int i,j;
        for(i=n-1;i>=0;i--)
        {
            k-=i;
            if(k>=26)
            {
                res+='z';
                k-=26;
            }
            else
            {
                char ch='a'+k-1;
                res+=ch;
                k-=ch-'a'+1;
                
            }
            //cout<<k<<" "<<res<<endl;
            k+=i;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};