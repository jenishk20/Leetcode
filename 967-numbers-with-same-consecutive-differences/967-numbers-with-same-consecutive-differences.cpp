class Solution {
public:
    void recur(int num,int n,int k,vector<int>&ans)
    {
        
        if(n==0)
            ans.push_back(num);
        else{
        int last=num%10;
        if(last+k<=9)
            recur(num*10+last+k,n-1,k,ans);
        if(k!=0 and last-k>=0)
            recur(num*10+last-k,n-1,k,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int>ans;
        
        for(int i=1;i<=9;i++)
        {
            recur(i,n-1,k,ans);
        }
      
        
        return ans;
    }
};