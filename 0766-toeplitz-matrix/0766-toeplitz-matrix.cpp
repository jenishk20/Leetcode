class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int i,j;
        j=0;
        i=0;
        while(i<n and j<m)
        {
            int ti=i;
            int tj=j;
            set<int>se;
            while(ti<n and tj<m)
            {
                se.insert(matrix[ti][tj]);
                ti++;
                tj++;
                
            }
            if(se.size()!=1) return false;
            
            j++;
            if(j==m)
            {
                j=0;
                i++;
            }
            
        }
        return true;
    }
};