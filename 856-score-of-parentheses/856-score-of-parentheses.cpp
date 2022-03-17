class Solution {
public:
    int scoreOfParentheses(string s) {
        
       stack<int>se;
       int n=s.size();
       int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                se.push(0);
            else
            {
                int val=0;
                while(!se.empty() and se.top()!=0)
                    val+=se.top(),se.pop();
                val=max(val*2,1);
                se.pop();
                se.push(val);
                
            }
        }
        while(!se.empty())
            count+=se.top(),se.pop();
        return count;
    }
};