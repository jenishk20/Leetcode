class Solution {
private:
    long long sumOfNaturalNumbers(long long n)
    {
        return (n*(n+1))/2;
    }
    long long rangeSum(long long l,long long r)
    {
        if(l==r)
            return l;
        if(l>r)
            return 0ll;
        
        return sumOfNaturalNumbers(r)-sumOfNaturalNumbers(l-1);
    }
public:
    
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int taken=0;
        int canTake=0;
        long long sum=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(taken==k)
                break;
            if(i==0)
            {
               canTake=nums[i]-1;
               if(taken+canTake<=k)
               {
                  
                   sum+=(rangeSum(1,nums[i]-1));
                   taken+=canTake;
               }
               else
               {
                   
                   sum+=(rangeSum(1,k));
                   taken=k;
                   break;
               }
            }
            else
            {
                if(nums[i]==nums[i-1] or nums[i]==nums[i-1]+1)
                    continue;
                canTake=nums[i]-nums[i-1]-1;
                if(taken+canTake<=k)
                {
                   taken+=canTake;
                   sum+=(rangeSum(nums[i-1]+1,nums[i]-1));
                }
                else
                {
                  
                   sum+=(rangeSum(nums[i-1]+1,nums[i-1]+k-taken));
                   taken=k;
                   break;
                }
            }
           // cout<<i<<" "<<sum<<" "<<taken<<endl;
        }
        if(taken<k)
        {
            sum+=(rangeSum(nums[n-1]+1,nums[n-1]+k-taken));
        }
        return sum;
    }
};