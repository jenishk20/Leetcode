class Solution {
public:
    int count(string s)
    {
        int n=s.size();
        int c=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
                c++;
        }
        return c;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        map<string,int>ma;
        
        for(int i=0;i<messages.size();i++)
        {
            ma[senders[i]]+=count(messages[i]);
        }
        int mx=0;
        for(auto i:ma)
        {
            mx=max(mx,i.second);
            
        }
        //cout<<mx<<endl;
        string ans="";
        for(auto i:ma)
        {
           if(i.second==mx)
              ans=i.first;
            
        }
        return ans;
    }
};