class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n=rating.size();
      
        
        int i,j;
        int res=0;
        for(i=1;i<n-1;i++)
        {
            
            int left_small=0,left_big=0,right_small=0,right_big=0;
            
            for(j=0;j<i;j++)
            {
                if(rating[j]<rating[i])
                    left_small++;
                else
                    left_big++;
            }
            for(j=i+1;j<n;j++)
            {
                if(rating[j]>rating[i])
                    right_big++;
                else
                    right_small++;
            }
            
            res+=(left_small*right_big)+(left_big*right_small);

        }
        return res;
    }
};