class Solution {
public:
    const int mod=1e9+7;
    int concatenatedBinary(int n) {
        
        long long int ans=0;
        int p=0;
        for(int i=1;i<=n;i++)
        {
            
            int tt=log2(i);
           
            ans=((ans<<(tt+1))%mod+i)%mod;
             //cout<<i<<" "<<tt<<" "<<ans<<endl;
        }
        return ans;
    }
};