class Solution {
public:
    bool isPowerOfFour(int n) {
        
        
        if(n<=0)
            return false;
        int k=n&(n-1);
        int p=n&(0xaaaaaaaa);
        
        return k==0 and p==0;
    }
};