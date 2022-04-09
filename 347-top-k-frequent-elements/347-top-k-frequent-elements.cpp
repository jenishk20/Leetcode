class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>ma;
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        
        for(auto i:nums)
            ma[i]++;
        for(auto i:ma)
        {
            pq.push({i.second,i.first});
            if(pq.size()>k)
                pq.pop();
            
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};