// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int> > findDistance(vector<vector<char> >& m, int M, int N) 
    { 
        // Your code goes here
       
        int rows=m.size();
        int cols=m[0].size();
         vector<vector<int>>ans(rows,vector<int>(cols,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        int i,j;
        for(i=0;i<rows;i++)
        {
            for(j=0;j<cols;j++)
            {
                if(m[i][j]=='B')
                {
                    q.push({{i,j},0});
                    ans[i][j]=0;
                }
               
                else if(m[i][j]=='W')
                {
                    ans[i][j]=-1;
                }
                
                
            }
        }
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            auto i=x.first;
            int d=x.second;
            for(int k=0;k<4;k++)
            {
                int nx=i.first+dx[k];
                int ny=i.second+dy[k];
                
                if(nx>=0 and nx<rows and 
                ny>=0 and ny<cols and ans[nx][ny]==INT_MAX
             )
                {
                    ans[nx][ny]=1+d;
                    q.push({{nx,ny},d+1});
                }
            }
        }
        for(i=0;i<rows;i++)
        {
            for(j=0;j<cols;j++)
            {
                if(ans[i][j]==INT_MAX)
                ans[i][j]=-1;
            }
        }
        return ans;
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends