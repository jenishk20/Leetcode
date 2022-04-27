class Node
{
    public:
    int u,v,wt;
    Node(int _u,int _v,int _wt)
    {
        u=_u;
        v=_v;
        wt=_wt;
    }
};
class Solution {
public:
    static bool comp(Node o1,Node o2)
    {
        return o1.wt<o2.wt;
    }
    int findPar(int u,vector<int>&parent)
    {
        if(u==parent[u])
            return u;
        return parent[u]=findPar(parent[u],parent);
    }
    void merge(int pu,int pv,vector<int>&parent,vector<int>&rank)
    {
        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
          
        }
        else if(rank[pu]>rank[pv])
        {
             parent[pv]=pu;
        }
        else
        {
            rank[pu]++;
            parent[pv]=pu;
        }
        
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        int i,j,k;
        vector<Node>ve;
        map<int,pair<int,int>>ma;
        for(i=0;i<n;i++)
        {
            ma[i]={points[i][0],points[i][1]};
            
            for(j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                
               
                ve.push_back(Node(i,j,cost));
            }
        }
        
        
        sort(ve.begin(),ve.end(),comp);
        int cost=0;
        vector<int>parent(n+1),rank(n+1,0);
        for(i=0;i<=n;i++)
            parent[i]=i;
        
        
        for(i=0;i<ve.size();i++)
        {
            int u=ve[i].u;
            int v=ve[i].v;
            int wt=ve[i].wt;
            
            int pu=findPar(u,parent);
            int pv=findPar(v,parent);
            if(pu!=pv)
            {
                merge(pu,pv,parent,rank);
                cost+=wt;
            }
            
                
        }
        
        return cost;
    }
};