class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>>ans;
        
        vector<int>up,down;
        bool be=true;
        bool turn=(upper>lower)?1:0;
        for(auto i:colsum)
        {
            if(i==2)
            {
                if(upper<1 or lower<1)
                {
                    be=false;
                    break;
                    
                }
                upper--;
                lower--;
                up.push_back(1);
                down.push_back(1);
            }
            else if(i==1)
            {
                if(upper>=lower and upper>=1)
                {
                    upper--;
                    up.push_back(1);
                    down.push_back(0);
                }
                else if(lower>upper and lower>=1)
                {
                     lower--;
                    up.push_back(0);
                    down.push_back(1);
                }
                else
                {
                    be=false;
                    break;
                }
               
            }
            else
            {
                up.push_back(0);
                down.push_back(0);
            }
            
        }
        if(!be or upper or lower)
            return ans;
        ans.push_back(up);
        ans.push_back(down);
        
        return ans;
    }
};