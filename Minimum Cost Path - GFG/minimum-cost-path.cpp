// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int dx[4]={-1,0,1,0};
	int dy[4]={0,1,0,-1};

    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
       // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;
        int n=grid.size();
        q.push({grid[0][0],{0,0}});  
            vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
            dist[0][0]=grid[0][0];
            
            while(!q.empty())
            {
                int dis=q.top().first;
                int r=q.top().second.first;
                int c=q.top().second.second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int nx=dx[i]+r;
                    int ny=dy[i]+c;
                    
                    if(nx>=0 and nx<n and ny>=0 and ny<n)
                    {
                        if(dist[nx][ny]>dis+grid[nx][ny])
                        {
                            dist[nx][ny]=dis+grid[nx][ny];
                            q.push({dist[nx][ny],{nx,ny}});
                        }
                    }
                }
            }
        return dist[n-1][n-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends