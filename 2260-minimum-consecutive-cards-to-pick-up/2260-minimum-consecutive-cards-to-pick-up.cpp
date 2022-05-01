class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        map<int,int>first,second;
        map<int,vector<int>>occ;
        int n=cards.size();
        int i;
        for(i=0;i<n;i++)
        {
            occ[cards[i]].push_back(i);
           
        }
        int ans=1e9;
        for(auto i:occ)
        {
            int ele=i.first;
            vector<int>res=i.second;
            if(res.size()<2)
                continue;
            
            for(int j=0;j<res.size()-1;j++)
                ans=min(ans,res[j+1]-res[j]+1);
            
            // ans=min(ans,res[1]-res[0]+1);
        }
        if(ans==1e9)
            return -1;
        return ans;
       
        return 0;
    }
};