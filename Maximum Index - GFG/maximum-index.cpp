//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        
        vector<int>pmin(n),pmax(n);
        int i;
        pmin[0]=arr[0];
        for(i=1;i<n;i++)
        pmin[i]=min(arr[i],pmin[i-1]);
        
        pmax[n-1]=arr[n-1];
        for(i=n-2;i>=0;i--)
        pmax[i]=max(pmax[i+1],arr[i]);
        
        // for(i=0;i<n;i++)
        // {
            // cout<<pmin[i]<<" "<<pmax[i]<<endl;
        // }
        int j=0;
        i=0;
        int ans=0;
        while(i<n and j<n)
        {
            if(pmin[i]<=pmax[j])
            {
                ans=max(ans,j-i);
                j++;
                
            }
            else
            i++;
        }
        return ans;
        return 0;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends