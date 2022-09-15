class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        vector<int>original;
        int cnt=0;
        int n=changed.size();
        if(n&1) return {};
        int to=n/2;
        sort(changed.begin(),changed.end());
        map<int,int>ma;
        for(auto i:changed)
            ma[i]++;
        
        for(auto i:changed)
        {
            
            if(i==0 and ma[i]%2==0 and ma[i]>0)
            {
                ma[i]-=2;
                original.push_back(i);
                cnt++;
            }
            else if(i!=0 and ma[i]!=0 and ma[i*2]!=0)
            {
                ma[i]--;
                ma[i*2]--;
               
                cnt++;
                original.push_back(i);
            }
        }
        
        if(cnt==to) return original;
        return {};
        
    }
};