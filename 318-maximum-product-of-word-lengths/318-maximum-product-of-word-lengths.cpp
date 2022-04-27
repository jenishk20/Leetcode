class Solution {
public:
    int maxProduct(vector<string>& words) {
       
        int n=words.size();
        vector<int>mask(n,0);
        int i;
        for(i=0;i<n;i++)
        {
            int tmask=0;
            for(auto ch:words[i])
            {
                tmask |= (1<<(ch-'a'));
            }
            mask[i]=tmask;
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(!(mask[i] & mask[j]))
                {
                    int p=words[i].size();
                    int q=words[j].size();
                    ans=max(ans,p*q);
                }
            }
        }
        
        return ans;
    }
};