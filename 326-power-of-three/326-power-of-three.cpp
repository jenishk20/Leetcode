class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n<=0)
            return false;
        
        double ans=log10(n)/log10(3);
        if(ans==(int)ans)
            return true;
        
        return false;
    }
};