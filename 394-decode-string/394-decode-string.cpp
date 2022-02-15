class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        
        int n=s.size();
        int i;
        for(i=0;i<n;i++)
        {
            if(s[i]==']')
            {
                string temp="";
                while(!st.empty() and st.top()!='[')
                {
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
            
                string temp2="";
                while(!st.empty() and isdigit(st.top()))
                {
                    temp2=st.top()+temp2;
                    st.pop();
                }
                int times=stoi(temp2);
                string repeat;
               
                while(times--)
                    repeat+=temp;
                for(auto i:repeat)
                    st.push(i);
            }
            else
            {
                st.push(s[i]);
            }
        }
        string fres="";
        while(!st.empty())
        {
            fres=st.top()+fres;
            st.pop();
        }
        return fres;
    }
};