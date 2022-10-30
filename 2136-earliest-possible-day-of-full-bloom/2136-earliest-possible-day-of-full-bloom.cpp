class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>>ve;
        for(int i=0;i<plantTime.size();i++)
        {
            ve.push_back({plantTime[i],growTime[i]});
        }
        sort(ve.begin(),ve.end(),[](pair<int,int>&p1,pair<int,int>&p2){
           
            return p1.second>p2.second;
        });
        int startTime=0;
        int ans=0;
        for(int i=0;i<ve.size();i++)
        {
            startTime+=ve[i].first;
            ans=max(ans,startTime+ve[i].second);
        }
        return ans;
    }
};