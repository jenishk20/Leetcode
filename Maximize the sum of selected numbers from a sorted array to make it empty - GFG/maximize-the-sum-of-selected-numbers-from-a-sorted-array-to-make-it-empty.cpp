//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        map<int,int>ma;
        for(int i=0;i<n;i++)
        ma[a[i]]++;
        
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(ma[a[i]]!=0)
            {
                sum+=a[i];
                ma[a[i]]--;
                if(ma[a[i]-1]!=0)
                ma[a[i]-1]--;
            }
            
            //cout<<sum<<endl;
        }
        return sum;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends