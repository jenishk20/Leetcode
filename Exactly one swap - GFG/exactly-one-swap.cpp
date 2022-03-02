// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        // code here
        bool y = false;
       vector<long long> vec(26,0);
       long long n = S.length();
       for(int i=0;i<S.length();i++)
       {
           vec[S[i]-97]++;
       }
       // for(int i=0;i<26;i++)
       // cout<<vec[i]<<" ";
       
       long long tot = ((n-1)*(n))/2;
       // long long count=0;
       for(int i=0;i<26;i++)
       {
           if(vec[i]>1)
           {
               long long k = (((vec[i]-1)*(vec[i]))/2);
               y = true;
               tot = tot-k;
           }
       }
       if(y)
       return tot+1;
       
       return tot;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends