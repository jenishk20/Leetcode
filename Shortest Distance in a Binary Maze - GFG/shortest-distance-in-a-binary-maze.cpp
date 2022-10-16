//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dx[4]={-1,0,1,0};
  int dy[4]={0,1,0,-1};
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[source.first][source.second]=0;
        
        int i,j;
        queue<pair<int,int>>q;
        q.push({source.first,source.second});
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=dx[k]+curr.first;
                int ny=dy[k]+curr.second;
                
                if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny]==1
                and dis[nx][ny]>1+dis[curr.first][curr.second])
                {
                    dis[nx][ny]=1+dis[curr.first][curr.second];
                    q.push({nx,ny});
                }
            }
        }
        int ans=dis[destination.first][destination.second];
        return ans==INT_MAX?-1:ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends