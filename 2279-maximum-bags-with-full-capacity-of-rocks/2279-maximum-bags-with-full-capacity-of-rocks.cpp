class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<pair<int,int>>ve;
        int n=capacity.size();
        int i;
        for(i=0;i<n;i++)
        {
            ve.push_back({i,capacity[i]-rocks[i]});
        }
        sort(ve.begin(),ve.end(),[&](pair<int,int>p1,pair<int,int>p2)
             {
                 return p1.second<p2.second;
             });
        
        // for(auto i:ve)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        int c=0;
        for(auto i:ve)
        {
            if(i.second==0)
                c++;
            else if(i.second<=additionalRocks)
            {
                c++;
                additionalRocks-=i.second;
            }
            else
                break;
        }
        return c;
    }
};