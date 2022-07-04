// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
         int setBitsRequired=__builtin_popcountll(b);
       
        
        int x=0;
        for(int i=31;i>=0;i--)
        {
            if((1<<i)&a)
            {
              
                if(setBitsRequired>0)
                {
                    x|=(1<<i);
                    setBitsRequired--;
                }
                
            }
        }
        for(int i=0;i<=31;i++)
        {
            if(setBitsRequired)
            if(!((1<<i)&x))
            {
                x|=(1<<i);
                setBitsRequired--;
            }
        }
        //cout<<setBitsRequired<<endl;
        return x;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends