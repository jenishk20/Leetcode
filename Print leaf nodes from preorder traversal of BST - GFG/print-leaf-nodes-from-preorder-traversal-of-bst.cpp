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
        vector<int>ans;
        stack<int>se;
        se.push(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(!se.empty() and arr[i]<se.top()) se.push(arr[i]);
            else
            {
                int temp=se.top();
                int rem=0;
                while(!se.empty() and se.top()<arr[i])
                {
                    se.pop();
                    rem++;
                    
                }
                se.push(arr[i]);
                if(rem>=2)
                ans.push_back(temp);
            }
            
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