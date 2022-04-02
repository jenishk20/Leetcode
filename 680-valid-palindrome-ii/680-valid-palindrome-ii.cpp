class Solution {
public:
    bool isPal(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int n=s.size();
        int i,j;
        i=0;
        j=n-1;
        int del=0;
        while(i<j)
        {
           if(s[i]==s[j])
           {
              i++;
              j--;
           }
           else
           {
                return isPal(s,i+1,j) or isPal(s,i,j-1); 
           }
        }
        return 1;

    }
};