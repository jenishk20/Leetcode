#define ll long long 
#define maxi 1e18
class Solution {
public:
    void solve(int src,vector<vector<pair<ll,ll>>>&graph,vector<ll>&dis)
    {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            // cout<<node<<" "<<distance<<endl;
            
            if(distance>dis[node])
                continue;
            
            for(auto itr:graph[node])
            {
                if(dis[itr.first]>itr.second+dis[node])
                {
                    dis[itr.first]=itr.second+dis[node];
                    pq.push({dis[itr.first],itr.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<ll>dis1(n,maxi),dis2(n,maxi),dis3(n,maxi);
        
        vector<vector<pair<long long,long long>>>graph(n),reverse(n);
        
        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            int w=i[2];
            
            graph[u].push_back({v,w});
            reverse[v].push_back({u,w});
            
            
        }
        solve(src1,graph,dis1);
        solve(src2,graph,dis2);
        solve(dest,reverse,dis3);
        
        long long ans=maxi;
        // for(auto i:dis1)
        //     cout<<i<<" ";
        // cout<<endl;
        //  for(auto i:dis2)
        //     cout<<i<<" ";
        // cout<<endl;
        
        for(int i=0;i<=n-1;i++)
        {
            if(dis1[i]==maxi or dis2[i]==maxi or dis3[i]==maxi) continue;
            
            ans=min(ans,dis1[i]+dis2[i]+dis3[i]);
        }
        return ans==maxi?-1:ans;
         
        
            
        
        
    }
};