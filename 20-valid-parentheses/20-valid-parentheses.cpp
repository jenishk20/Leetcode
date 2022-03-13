class Solution {
public:
    bool isValid(string s) {
        
        stack<char>se;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
                se.push(s[i]);
            else
            {
                if(s[i]==')')
                {
                      if(se.empty())
                        return false;
                    if(se.top()=='(')
                        se.pop();
                    else
                        return false;
                }
                else if(s[i]=='}')
                {
                      if(se.empty())
                        return false;
                    if(se.top()=='{')
                        se.pop();
                    else
                        return false;
                }
                else if(s[i]==']')
                {
                    if(se.empty())
                        return false;
                    if(se.top()=='[')
                        se.pop();
                    else
                        return false;
                }
            }
        }
        return se.empty();
    }
};