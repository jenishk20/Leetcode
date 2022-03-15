class Solution {
public:
    int minOperations(int n) {
        
        vector<int>arr(n);
        int i;
        int sum=0;
        for(i=0;i<n;i++){
            arr[i]=2*i+1;
            sum+=arr[i];
        }
        sum/=n;
        int count=0;
        for(i=0;i<n;i++)
        {
            count+=(abs(arr[i]-sum));
        }
        return count/2;
        
    }
};