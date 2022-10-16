class MyCalendarThree {
public:
    map<int,int>ma;
    int ans=0;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        ma[startTime]++;
        ma[endTime]--;
        int count=0;
        for(auto it=ma.begin();it!=ma.end();it++)
        {
            count+=it->second;
            ans=max(ans,count);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */