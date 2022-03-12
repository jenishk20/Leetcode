class Solution {
public:
    long long int sumOfSquares(int x)
    {
        long long int sum=0;
        while(x)
        {
            int rem=x%10;
            sum+=rem*1ll*rem;
            x/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        
        long long int slow=n,fast=n;
        do
        {
            slow=sumOfSquares(slow);
            fast=sumOfSquares(fast);
            fast=sumOfSquares(fast);
            
            
        }while(slow!=fast);
        
        return slow==1;
        
    }
};