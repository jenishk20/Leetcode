class Solution {
public:
    int dp[1001][1001][2];
    int recur(string &s1,string &s2,int n,int m,int i,int j,bool include)
    {
        if(i>=n || j>=m)
        return 0;
        if(dp[i][j][include]!=-1)
        return dp[i][j][include];
        if(include)
        {
            if(s1[i]!=s2[j])
            return 0;
            
            return dp[i][j][include]= 1+recur(s1,s2,n,m,i+1,j+1,true);
        }
        if(s1[i]==s2[j])
        {
            int op1=recur(s1,s2,n,m,i+1,j+1,false);
            int op2=recur(s1,s2,n,m,i+1,j,false);
            int op3=recur(s1,s2,n,m,i,j+1,false);
            int op4=recur(s1,s2,n,m,i+1,j+1,true)+1;
            
            return dp[i][j][include]=max({op1,op2,op3,op4});
        }
        int op1=recur(s1,s2,n,m,i+1,j,false);
            int op2=recur(s1,s2,n,m,i,j+1,false);
            return dp[i][j][include]=max({op1,op2});
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        string s1="";
        string s2="";
        int i;
        for(i=0;i<nums1.size();i++)
            s1+=nums1[i]+'0';
        for(i=0;i<nums2.size();i++)
            s2+=nums2[i]+'0';
        memset(dp,-1,sizeof dp);
        return recur(s1,s2,s1.size(),s2.size(),0,0,false);
    }
};