class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        
        int n=tops.size();
        int i,j,k;
        int ans1=INT_MAX,ans2=INT_MAX;
        for(i=1;i<=6;i++)
        {
            bool be=true;
            int c=0;
            for(j=0;j<n;j++)
            {
               if(tops[j]==i)
                   continue;
                else if(bottoms[j]==i)
                    c++;
                else
                {
                    be=false;
                    break;
                }
                    
            }
            if(be)
                ans1=min(ans1,c);
                
        }
       for(i=1;i<=6;i++)
        {
            bool be=true;
            int c=0;
            for(j=0;j<n;j++)
            {
               if(bottoms[j]==i)
                   continue;
                else if(tops[j]==i)
                    c++;
                else
                {
                    be=false;
                    break;
                }
                    
            }
            if(be)
                ans2=min(ans2,c);
                
        }
        if(ans1==INT_MAX and ans2==INT_MAX)
            
        return -1;
        
        return min(ans1,ans2);
    }
};