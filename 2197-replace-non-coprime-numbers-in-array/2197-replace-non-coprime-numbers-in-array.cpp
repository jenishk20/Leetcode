class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
        
        for(auto  i:nums)
        {
            ans.push_back(i);
            while(ans.size()>=2)
            {
                
                int n=ans.size();
                long long int p1=ans[n-1];
                long long int p2=ans[n-2];
                int k=__gcd(p1,p2);
                
                if(k==1)
                    break;
                
                ans.pop_back();
                ans.pop_back();
                
                int lcm=(p1*p2)/k;
                ans.push_back(lcm);
                
                //cout<<p1<<" "<<p2<<" "<<lcm<<endl;
            }
        }
        return ans;
    }
};