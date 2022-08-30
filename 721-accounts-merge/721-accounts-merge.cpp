class Solution {
private : 
      map<string,vector<string>>graph;
      map<string,bool>vis;
      vector<vector<string>>ans;
public:
    void dfs(string &s,vector<string>&temp)
    {
        vis[s]=1;
        temp.push_back(s);
        for(auto i:graph[s])
        {
            if(!vis[i])
            {
                dfs(i,temp);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        
        int n=accounts.size();
            
        for(auto &acc:accounts)
        {
            for(int j=2;j<acc.size();j++)
            {
                string u=acc[j-1];
                string v=acc[j];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
     
        
        for(auto i:graph)
        {
            cout<<i.first<<" ";
            for(auto it:i.second)
                cout<<it<<" ";
            cout<<endl;
        }
        // vector<string>vis(n+1,0);
        for(auto i:accounts)
        {
            cout<<i[0]<<" "<<i[1]<<endl;
            if(!vis[i[1]])
            {
                cout<<i[1]<<endl;
                vector<string>temp;
                dfs(i[1],temp);
                sort(temp.begin(),temp.end());
                temp.insert(temp.begin(),i[0]);
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};