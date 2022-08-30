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
     
        
        
        for(auto i:accounts)
        {
            
            if(!vis[i[1]])
            {
               
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