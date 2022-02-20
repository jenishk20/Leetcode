class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        priority_queue<pair<char,int>>pq;
        map<char,int>hash;
        for(auto i:s)
            hash[i]++;
        
        for(auto i:hash)
            pq.push({i.first,i.second});
        
        string res="";
        while(!pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            
            int k=min({t.second,repeatLimit});
            t.second-=k;
            
            res+=string(k,t.first);
            if(pq.empty() or t.second==0)
                continue;
            
            auto t1=pq.top();
            pq.pop();
            res+=t1.first;
            t1.second--;
            
            if(t1.second)
            pq.push({t1.first,t1.second});
            
            pq.push({t.first,t.second});
        }
        return res;
    }
};