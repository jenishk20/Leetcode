class Solution {
public:
    bool isPowerOfFour(int n) {
        
        
        if(n<=0)
            return false;
        
        return (n&(n-1))==0  and (n&(0xaaaaaaaa))==0;
    }
};