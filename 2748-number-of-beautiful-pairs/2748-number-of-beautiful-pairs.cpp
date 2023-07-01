class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        
        int n=nums.size();
        int i,j;
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(i==j) continue;
                string f = to_string(nums[i]);
                int fd = f[0]-'0';
                
                string t = to_string(nums[j]);
                int ld = t[t.size()-1]-'0';
                
                if(__gcd(fd,ld)==1){
                    //cout<<i<<" "<<j<<" "<<fd<<" "<<ld<<endl;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};