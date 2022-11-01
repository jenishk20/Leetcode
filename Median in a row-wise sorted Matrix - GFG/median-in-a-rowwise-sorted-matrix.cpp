//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int countElementsLessThanMid(vector<int>&v, int x)

{

    int lo=0, hi=v.size()-1;

    int cnt=0;

    while(lo<=hi)  

    {

        int mid=lo+(hi-lo)/2; 

        if(v[mid] < x){        // Checking for next highest element

            cnt = (mid+1); // 0th-based indexing

            lo=mid+1;

        }   

        else

            hi=mid-1;

    }

    return cnt;

}


    int median(vector<vector<int>> &A, int R, int C){
        // code here    
        
      int n=A.size(),m=A[0].size();

    // int lo=1;

    // int hi=1e9;

    

    // find min or max element in a matrix using first or last elements of each row respectively.

    int lo = INT_MAX, hi = INT_MIN;

    for(int i=0;i<n;i++){

        lo = min(lo, A[i][0]);

        hi = max(hi, A[i][m-1]);

    }

    

    int ans;

    while(lo<=hi)

    {

        int mid=lo+(hi-lo)/2;

        int count=0;

        // Every single row is sorted SO make use of that via Binary search

        for(int i=0;i<n;i++)

            count += countElementsLessThanMid(A[i], mid);

            
        //cout<<count<<endl;
        if(count<=(n*m/2)){

            ans=mid;

            lo=mid+1;

        }

        else

            hi=mid-1;

    }

    return ans;      
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends