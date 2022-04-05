class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<=j)
        {
            int base=j-i;
            if(height[i]>=height[j])
            {
                ans=max(ans,base*height[j]);
                j--;
            }
            else
            {
                ans=max(ans,base*height[i]);
                i++;
            }
        }
        return ans;
    }
};