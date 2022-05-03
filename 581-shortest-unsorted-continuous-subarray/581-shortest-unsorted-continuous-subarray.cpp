class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int i;
        int st=-1;
        int en=-1;
        int maxTillNow=INT_MIN;
        
        for(i=0;i<n;i++)
        {
            if(nums[i]<maxTillNow)
            {
                if(st==-1)
                    st=i;
                while(st-1>=0 and nums[st-1]>nums[i])
                {
                    st--;
                }
                en=i+1;
            }
            else
            {
                maxTillNow=nums[i];
            }
           // cout<<st<<" "<<en<<endl;
        }
  
     
     return en-st;
            
       
        
    }
};