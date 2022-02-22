class TopVotedCandidate {
public:
    
    priority_queue<pair<int,int>>pq;
    map<int,int>ma;
    vector<int>time;
    vector<int>lead;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        
        time=times;
        int i;
        
        for(i=0;i<persons.size();i++)
        {
            ma[persons[i]]++;
            
            if(pq.empty())
            {
                pq.push({ma[persons[i]],persons[i]});
            }
            else
            {
                auto x=pq.top();
                if(ma[persons[i]]>=x.first)
                {
                   pq.pop();
                   pq.push({ma[persons[i]],persons[i]});
                }
            }
            lead.push_back(pq.top().second);
        }
        // for(auto i:lead)
        //     cout<<i<<" ";
        // cout<<endl;
    }
    
    int q(int t) {
        
        
        int idx=lower_bound(time.begin(),time.end(),t)-time.begin();
        //cout<<idx<<endl;
        
        if(idx==lead.size())
            return lead[idx-1];
        if(time[idx]==t)
        return lead[idx];
        
        
        
        return  lead[idx-1];
        
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */