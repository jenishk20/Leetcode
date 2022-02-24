class Solution {
public:
    bool check(int force,vector<int>&position,int balls)
    {
        int n=position.size();
        long long can_place=0;
        long long put=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                can_place++;
            }
            else if((position[i]-position[put])>=force)
            {
                can_place++;
                put=i;
            }
        }
        //cout<<can_place<<endl;
        return can_place>=balls;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        
        long long  low=0;
        long long high=0;
        for(auto i:position)
            high+=i;
        long long ans=0;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            
             // cout<<mid<<" ";
            if(check(mid,position,m))
            {
                
                ans=mid;
                low=mid+1;
            }
            else
            {
                
               high=mid-1;
            }
        }
        return ans;
        
    }
};