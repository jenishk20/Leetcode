class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n=nums.size();
        int i,j;
        vector<long long>pfx(n,0),sfx(n,0);
        pfx[0]=nums[0];
        sfx[n-1]=0;
        
        for(i=1;i<n;i++)
            pfx[i]+=pfx[i-1]+nums[i];
        for(i=n-2;i>=0;i--)
            sfx[i]+=sfx[i+1]+nums[i+1];
        
        // for(i=0;i<n;i++)
        // {
        //     cout<<pfx[i]<<" "<<sfx[i]<<endl;
        // }
        int c=0;
        for(i=0;i<n-1;i++)
        {
            if(pfx[i]>=sfx[i])
                c++;
        }
        return c;
    }
};