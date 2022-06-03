class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](vector<int>&a,vector<int>&b){
            if(a[1]==b[1])
                return a[2]<b[2];
            return a[1]<b[1];
        });
        
        map<int,int>ma;
        for(auto it:trips)
        {
            ma[it[1]]+=it[0];
            ma[it[2]]-=it[0];
        }
    
        for(auto it:ma)
        {
            if(capacity-it.second<0)
                return false;
            
            capacity-=it.second;
        }
        return 1;
        
    }
};