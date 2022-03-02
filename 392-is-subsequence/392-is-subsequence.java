class Solution {
    public boolean recur(String s,String t,int n,int m)
    {
        
        if(n==0)
            return true;
        if(m==0)
            return false;
        
        if(s.charAt(n-1)==t.charAt(m-1))
            return recur(s,t,n-1,m-1);
        
       
        boolean op2=recur(s,t,n,m-1);
        
        return op2;
    }
    public boolean isSubsequence(String s, String t) {
        
        int n=s.length();
        int m=t.length();
        
        return recur(s,t,n,m);
    }
}