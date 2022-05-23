class Solution {
public:
    int minimumLines(vector<vector<int>>& stocks) {
        
        sort(stocks.begin(),stocks.end());
        int n=stocks.size();
        int i;
        
        if(stocks.size()<=1)
            return 0;
        int c=1;
        
        for(i=1;i<n-1;i++)
        {
            int x1=stocks[i-1][0];
            int y1=stocks[i-1][1];
            
            int x2=stocks[i][0];
            int y2=stocks[i][1];
            
            int x3=stocks[i+1][0];
            int y3=stocks[i+1][1];
            
            
            double slope1=(long double)(y2-y1)/(x2-x1);
            double slope2=(long double)(y3-y2)/(x3-x2);
            
            long long op1=(y2-y1)*1ll*(x3-x2);
            long long op2=(y3-y2)*1ll*(x2-x1);
            if(op1!=op2)
                c++;
        }
        return c;
    }
};