//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int n) {
        // code here
        stack<int>se;
        vector<int>ans;
        int i=0,j=1;
        while(j<n)
        {
            if(arr[i]>arr[j])
            se.push(arr[i]);
            
            else
            {
                bool found=false;
                while(!se.empty() and arr[j]>se.top())
                {
                    found=true;
                    se.pop();
                }
                if(found)
                ans.push_back(arr[i]);
            }
            
            i++;
            j++;
        }
        ans.push_back(arr[n-1]);
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends