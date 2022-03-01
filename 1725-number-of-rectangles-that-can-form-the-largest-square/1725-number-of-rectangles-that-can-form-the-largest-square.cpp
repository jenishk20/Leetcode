class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
          int n=rectangles.size();
        map<int,int>ma;
        for(auto i:rectangles)
        {
            ma[min(i[0],i[1])]++;
        }
        int ans=0;
        for(auto i:ma)
        {
            //cout<<i.first<<" "<<i.second<<endl;
            ans=max(ans,i.first);
        }
       // cout<<ans<<endl;
        int c=0;
        for(auto i:ma)
            if(i.first==ans)
                c+=i.second;
        return c;
    }
};