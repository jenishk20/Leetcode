//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	int mod=1e9+7;
		int NthTerm(int n){
		    // Code  here
		        vector<long long>a(n+1);
		        a[0]=1;
		        a[1]=2;
		        int st=2;
		        for(int i=2;i<=n;i++)
		        {
		            a[i]=((a[i-1]%mod)*(st%mod)%mod)+1;
		            st++;
		        }
		        return a[n];
		    
		  }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends