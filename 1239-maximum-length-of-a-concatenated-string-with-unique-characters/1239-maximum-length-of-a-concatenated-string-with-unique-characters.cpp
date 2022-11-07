class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int tot=pow(2,n)-1;
        int i,j;
        int ans=0;
        for(i=0;i<=tot;i++)
        {
            
            string merged="";
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                    merged+=arr[j];
                    // cout<<arr[j]<<" ";
            }
            int freq[26]={0};
            for(int i=0;i<merged.size();i++)
            {
                freq[merged[i]-'a']++;
            }
            int cnt=0;
            for(int i=0;i<26;i++)
            {
                if(freq[i]==1)
                {
                    cnt++;
                }
                else if(freq[i]>1)
                {
                    cnt=0;
                    break;
                }
            }
            ans=max(ans,cnt);
            // maxlength=max(maxlength,cnt);     
        }
        return ans;
    }
};