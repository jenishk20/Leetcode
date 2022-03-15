class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>se;
        bool be=false;
        
        int n=s.size();
        string res="";
        vector<int>idx;
        int i;
        for(i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                if(se.empty()){
                    res+=s[i];
                    idx.push_back(i);
                    continue;
                }
                else
                {
                    res+=s[i];
                    se.pop();
                    
                }
            }
            else if(s[i]=='(')
            {
                res+=s[i];
                
                se.push({s[i],i});
            }
            else
                res+=s[i];
        }
        
        while(!se.empty())
        {
            auto curr=se.top();
            se.pop();
            idx.push_back(curr.second);
            
        }
        string fres="";
        int k=0;
      
        sort(idx.begin(),idx.end());
          for(auto i:idx)
            cout<<i<<" ";
        cout<<endl;
        for(i=0;i<res.size();i++)
        {
            if(k<idx.size() and i==idx[k])
            {
                k++;
                continue;
            }
            cout<<res[i]<<" ";
            fres+=res[i];
        }
        
        return fres;
        
    }
};