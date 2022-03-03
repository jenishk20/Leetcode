// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool check(int n ,int m, int x,int y){
       return x>=0 && y>=0 && x<n && y<m;
   }
   pair<int,int> endPoints(vector<vector<int>> matrix){
       //code here
       pair<int,int>right = {0,1};
       pair<int,int>left = {0,-1};
       pair<int,int>up = {-1,0};
       pair<int,int>down = {1,0};
       
       queue<pair<int,int>>q;
       q.push({0,0});
       while(!q.empty())
       {
           auto node = q.front();
           q.pop();
           
           
           if(matrix[node.first][node.second] == 1){
                  pair<int,int>temp = up;
                  up = right;
                  right = down;
                  down  = left;
                  left = temp;
                  matrix[node.first][node.second] = 0;
           }
           if(check(matrix.size() , matrix[0].size() , node.first+right.first ,node.second+right.second) == true)
           {
                q.push({node.first + right.first , node.second + right.second});
                
           }
           else{
               return {node.first , node.second};
           }
          
           
       }
   }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends