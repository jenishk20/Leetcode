class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        string res="";
        priority_queue<pair<int,char>>pq;
        if(a!=0)
        pq.push({a,'a'});
        if(b!=0)
        pq.push({b,'b'});
        if(c!=0)
        pq.push({c,'c'});
        char lp;
        while(!pq.empty())
        {
          
            pair<int,char>p1=pq.top();
            pq.pop();
            
            if(res.size()==0 or res.back()!=p1.second)
            {
                int k=min(p1.first,2);
                p1.first-=k;
                while(k--)
                    res+=p1.second;
                if(p1.first>0)
                    pq.push(p1);
            }
            else
            {
                if(pq.empty())
                    break;
                 pair<int,char>p2=pq.top();
                 pq.pop();
                 res+=p2.second;
                p2.first-=1;
                if(p2.first>0)
                    pq.push(p2);
                pq.push(p1);
            }
            
                
        }
        return res;
    }
};