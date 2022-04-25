class UndergroundSystem {
public:
    map<int,pair<string,int>>ma;
    map<pair<string,string>,vector<int>>ma1;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ma[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        
        string enterStation=ma[id].first;
        int entryTime=ma[id].second;
        ma1[{enterStation,stationName}].push_back(t-entryTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double ans=0;
        int ele=ma1[{startStation,endStation}].size();
        for(auto i:ma1[{startStation,endStation}])
            ans+=i;
        
        return ans/ele*1.0;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */