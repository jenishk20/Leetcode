class Solution {
public:
    void recur(vector<string>&words,int idx,vector<string>ds,vector<int>&freq,vector<vector<string>>&ans)
    {
       
        if(!ds.empty())
        ans.push_back(ds);
        
        for(int i=idx;i<words.size();i++)
        {
            
                ds.push_back(words[i]);
                recur(words,i+1,ds,freq,ans);
                ds.pop_back();
               
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n=words.size();
        vector<string>ds;
        vector<int>freq(n+1,0);
        vector<vector<string>>ans;
        recur(words,0,ds,freq,ans);
        
        map<char,int>mappings,required;
        char ch='a';
        for(auto i:score)
            mappings[ch++]=i;
        for(auto i:letters)
            required[i]++;
        
        
        // for(auto i:required)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        int result=0;
        for(auto i:ans)
        {
           map<char,int>have;
            int sum=0;
           vector<string>res=i;
           for(auto it:res)
           {
              // cout<<it<<" ";
               string temp=it;
               for(auto it2:temp)
                   have[it2]++;
           }
           
           for(auto it:have)
           {
               if(required[it.first]<it.second){
                   goto brk;
               }
               sum+=(mappings[it.first]*it.second);
           }
            
          
           result=max(result,sum);
           brk:;
        }
        return result;
        
    }
};