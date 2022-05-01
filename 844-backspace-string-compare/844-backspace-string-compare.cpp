class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>se,se1;
        string res="",res1="";
        
        for(auto i:s)
        {
            if(i=='#')
            {
                if(!se.empty())
                    se.pop();
            }
            else
            {
                se.push(i);
            }
        }
         for(auto i:t)
        {
            if(i=='#')
            {
                if(!se1.empty())
                    se1.pop();
            }
            else
            {
                se1.push(i);
            }
        }
        while(!se.empty())
        {
            res+=se.top();
            se.pop();
        }
        while(!se1.empty())
        {
            res1+=se1.top();
            se1.pop();
        }
        return res==res1;
        
    }
};