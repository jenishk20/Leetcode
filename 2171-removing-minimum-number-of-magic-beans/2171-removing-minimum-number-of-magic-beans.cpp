class Solution {
public:
    long long recur(vector<int>&beans,vector<long long >&sfx,int idx,int n)
    {
        if(idx==n-1)
        {
            return 0ll;
        }
        long long op1=beans[idx]+recur(beans,sfx,idx+1,n);
        long long op2=sfx[idx]-(n-idx-1);
        
        return min(op1,op2);
    }
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        int i=0;
        int n=beans.size();
        long long ans=1e16;
        vector<long long>sfx(n+1,0);
        vector<long long>pfx(n+1,0);
        sfx[n-1]=0;
        pfx[0]=0;
        for(i=1;i<n;i++)
        {
            pfx[i]=pfx[i-1]+beans[i-1];
        }
        for(i=n-2;i>=0;i--)
        {
            sfx[i]=sfx[i+1]+beans[i+1];
        }
//         for(i=0;i<n;i++)
//         {
//             cout<<pfx[i]<<" "<<sfx[i]<<endl;
            
//         }
        
        for(i=0;i<n;i++)
        {
            long long res=pfx[i]+(sfx[i]-(n-i-1)*1ll*beans[i]);
          //  cout<<res<<endl;
            ans=min(ans,res);
        }
        
        return ans;
    }
};