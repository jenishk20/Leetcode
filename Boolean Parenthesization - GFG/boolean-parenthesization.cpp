// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[201][201][2];
const int mod=1003;
int recur(int i,int j,bool isTrue,string &s)
{
    if(i>j) return 0;
    if(i==j) {
        if(isTrue) return s[i]=='T';
        else return s[i]=='F';
    }
    int ways=0;
    if(dp[i][j][isTrue]!=-1)
    return dp[i][j][isTrue];
    for(int idx=i+1;idx<=j-1;idx+=2)
    {
        int lt=recur(i,idx-1,1,s);
        int rt=recur(idx+1,j,1,s);
        int lf=recur(i,idx-1,0,s);
        int rf=recur(idx+1,j,0,s);
        
        if(s[idx]=='&'){
            if(isTrue)
            ways+=(lt*rt)%mod;
            else
            ways+=(rt*lf+rf*lt+rf*lf)%mod;
        }
        
        
        else if(s[idx]=='^'){
            if(isTrue)
            {
                ways+=(lt*rf+lf*rt)%mod;
            }
            else
            {
                ways+=(lt*rt+lf*rf)%mod;
            }
        }
        
        
        else
        {
            if(isTrue)
            {
               ways+=((lt*rt)+(lt*rf)+(rt*lf))%mod;
            }
            else
            ways+=(lf*rf)%mod;
        }
        
    }
    return dp[i][j][isTrue]=ways%mod;
}
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof dp);
        return recur(0,N-1,1,S);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends