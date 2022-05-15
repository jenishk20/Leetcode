class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int n=candidates.size();
        int i;
        map<int,int>ma;
        int mx=0;
        for(i=31;i>=0;i--)
        {
            int c=0;
            for(auto it:candidates)
            {
                if(it&(1<<i))
                    c++;
            }
            mx=max(mx,c);
        }
       
        return mx;
    }
};