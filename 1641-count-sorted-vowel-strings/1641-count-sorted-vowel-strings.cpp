class Solution {
public:
    int recur(int n,string s,int idx)
    {
        if(n==0)
            return 1;
        if(idx>=5)
            return 0;
        
        return recur(n-1,s,idx)+recur(n,s,idx+1);
    }
    int countVowelStrings(int n) {
        
        string s="aeiou";
        return recur(n,s,0);
    }
};