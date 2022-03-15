class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>se;
      
        int n=s.size();
        vector<int>idx;
        int i;
        for(i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                if(se.empty()){
                   
                    idx.push_back(i);
                    continue;
                }
                else
                {
                   
                    se.pop();
                    
                }
            }
            else if(s[i]=='(')
            {
                
                
                se.push({s[i],i});
            }
           
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
        for(i=0;i<s.size();i++)
        {
            if(k<idx.size() and i==idx[k])
            {
                k++;
                continue;
            }
         
            fres+=s[i];
        }
        
        return fres;
        
    }
};