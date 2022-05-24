class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        int i;
        int ml=0;
        stack<int>se;
        se.push(-1);
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                se.push(i);
            else
            {
                se.pop();
                if(se.empty())
                    se.push(i);
                else
                    ml=max(ml,i-se.top());
            }
        }
        return ml;
    }
};