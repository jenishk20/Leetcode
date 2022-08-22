class Solution {
public:
    bool isPowerOfFour(int n) {
        
        
        if(n<=0)
            return false;
        int cnt=0;
        bool flag=false;
        for(int i=0;i<=31;i++)
        {
            if(n&(1<<i))
            {
                if(i%2==0)
                    flag=1;
                cnt++;
            }
            
        }
        return flag and cnt==1;
    }
};