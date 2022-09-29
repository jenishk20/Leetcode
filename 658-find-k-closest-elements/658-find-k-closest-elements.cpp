class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++)
        {
           
            pq.push({abs(arr[i]-x),arr[i]});
        }
        while(!pq.empty() and k)
        {
            
            auto curr=pq.top();
            pq.pop();
            k--;
            ans.push_back(curr.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};