class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int  n=pushed.size();
        stack<int>se;
        int i,j=0;
        for(i=0;i<n;i++)
        {
            se.push(pushed[i]);
            while(!se.empty() and se.top()==popped[j])
            {
                se.pop();
                j++;
            }
        }
        return se.empty();
    }
};