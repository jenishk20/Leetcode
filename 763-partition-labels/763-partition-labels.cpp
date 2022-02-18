class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        map<char,int>lastOcc;
        int n=s.size();
        vector<int>res;
        int i;
        for(i=0;i<n;i++)
        {
            lastOcc[s[i]]=i;
        }
        int curr=lastOcc[s[0]];
        int prev=0;
        for(i=0;i<n;i++)
        {
            //cout<<s[i]<<" "<<curr<<endl;
            
            curr=max(curr,lastOcc[s[i]]);
            if(i==curr){
                res.push_back(i+1-prev);
                prev=i+1;
                curr=lastOcc[s[i]];
            }
            
           

        }
        
        return res;
        
    }
};