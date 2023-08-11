//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long dp[1001][1001];
  long long recur(int coins[],int N,int sum,int i)
  {
      if(i==0)
      {
          return sum%coins[0]==0;
      }
      if(dp[i][sum]!=-1)
      return dp[i][sum];
      
      long long notTake = recur(coins,N,sum,i-1);
      long long take =0 ;
      if(sum>=coins[i])
      {
          take = recur(coins,N,sum-coins[i],i);
      }
      return dp[i][sum]=take + notTake;
      
      
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        memset(dp,-1,sizeof dp);
        return recur(coins,N,sum,N-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends