class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
            
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        
        int n=envelopes.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(i==0)
                res.push_back(envelopes[i][1]);
            else if(res.back()<envelopes[i][1])
                res.push_back(envelopes[i][1]);
            
            else
            {
               
                auto it=lower_bound(res.begin(),res.end(),envelopes[i][1])-res.begin();
                
                res[it]=envelopes[i][1];
                
            }
                
        }
        return res.size();
    }
};