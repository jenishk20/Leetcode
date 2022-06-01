class Solution {
public:
    string reorganizeString(string s) {
        
        string res="";
        map<char,int>ma;
        int n=s.size();
        for(int i=0;i<n;i++)
            ma[s[i]]++;
        priority_queue<pair<int,char>>pq;
        for(auto i:ma)
        {
            pq.push({i.second,i.first});
        }
        while(!pq.empty())
        {
            if(pq.size()==1 and pq.top().first==1){
                res+=pq.top().second;
                break;
            }
            else if(pq.size()==1)
                return "";
            
            pair<int,char>p1=pq.top();
            pq.pop();
            pair<int,char>p2=pq.top();
            pq.pop();
            
            
            res+=p1.second;
            p1.first--;
            res+=p2.second;
            p2.first--;
            if(p1.first!=0)
            pq.push(p1);
            if(p2.first!=0)
            pq.push(p2);
            
        }
        return res;
    }
};