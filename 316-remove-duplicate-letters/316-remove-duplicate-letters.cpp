class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char>st;
        map<char,int>lastIndex;
        map<char,bool>used;
        int i;
        int n=s.size();
        for(i=0;i<n;i++)
            lastIndex[s[i]]=i;
        
        for(i=0;i<n;i++)
        {
            if(used[s[i]])
                continue;
            while(!st.empty() and st.top()>s[i] and i<lastIndex[st.top()])
            {
                 used[st.top()]=0;
                st.pop();
               
            }
            st.push(s[i]);
            used[s[i]]=1;
        }
        string ans="";
        while(!st.empty())
        {
           
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};