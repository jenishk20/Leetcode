//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int recur(int i,int j,int idx,vector<vector<int>>&vis,vector<vector<char>>&mat,string target)
    {
        
        if(idx==target.size())
        return 1;
        
        vis[i][j]=1;
        int count=0;
        
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            
            if(nx>=0 and ny>=0 and nx<mat.size() and ny<mat[0].size() and
            !vis[nx][ny] and mat[nx][ny]==target[idx])
            {
                count+=recur(nx,ny,idx+1,vis,mat,target);
                vis[nx][ny]=0;
            }
        }
        return count;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        
        int n=mat.size();
        int m=mat[0].size();
        
        int i,j;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j] and mat[i][j]==target[0])
                {
                    
                    ans+=recur(i,j,1,vis,mat,target);
                    vis[i][j]=false;
                    
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends