class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>se;
        int count=0;
        for(auto i:s)
        {
            if(i=='(')
                se.push(i);
            else
            {
                if(se.empty())
                    count++;
                else
                    se.pop();
            }
        }
        return count+se.size();
    }
};