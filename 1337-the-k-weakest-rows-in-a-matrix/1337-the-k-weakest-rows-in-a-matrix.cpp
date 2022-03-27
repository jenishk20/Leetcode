class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int,int>>maxHeap;
        
        int r=mat.size();
        int c=mat[0].size();
        int i,j;
        
        for(i=0;i<r;i++)
        {
            int co=0;
            for(j=0;j<c;j++)
                if(mat[i][j])
                    co++;
            maxHeap.push({co,i});
            if(maxHeap.size()>k)
                maxHeap.pop();
        }
        vector<int>ans;
        while(!maxHeap.empty())
        {
            //cout<<maxHeap.top().first<<" "<<maxHeap.top().second<<endl;
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};