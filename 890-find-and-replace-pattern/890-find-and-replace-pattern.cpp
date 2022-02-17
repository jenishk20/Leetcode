class Solution {
public:
    vector<int>findPermutation(string s)
    {
        
         vector<int>perm;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int count=1;
            while(i<n and s[i]==s[i+1])
            {
                i++;
                count++;
            }
            perm.push_back(count);
        }
        return perm;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        
        vector<string>ans;
       
        
        int i;
       
         vector<int>patternPermutation=findPermutation(pattern);
       
        // for(auto i:patternPermutation)
        //     cout<<i<<" ";
        // cout<<endl;
        for(i=0;i<words.size();i++)
        {
            vector<int>wordPermutation=findPermutation(words[i]);
            //  for(auto i:wordPermutation)
            //  cout<<i<<" ";
            // cout<<endl;
            if(wordPermutation==patternPermutation)
            {
                map<char,char>ma,ma1;
                int k=0;
                bool be=true;
                cout<<words[i]<<endl;
                for(int j=0;j<words[i].size();j++)
                {
                    if(ma.find(pattern[k])!=ma.end())
                    {
                        if(words[i][j]!=ma[pattern[k]])
                        {
                            be=false;
                            break;
                        }
                    }
                    else
                    {
                        ma[pattern[k]]=words[i][j];
                    }
                    if(ma1.find(words[i][j])!=ma1.end())
                    {
                        if(ma1[words[i][j]]!=pattern[k])
                        {
                            be=false;
                            break;
                        }
                    }
                    else
                    {
                        ma1[words[i][j]]=pattern[k];
                    }
                    k++;
                }
//                 for(auto itr:ma)
//                 {
//                     cout<<itr.first<<" "<<itr.second<<endl;
//                 }
//                 cout<<endl;
//                 for(auto itr:ma1)
//                 {
//                     cout<<itr.first<<" "<<itr.second<<endl;
                    
//                 }
//                 for(auto itr:ma)
//                 {
//                     //cout<<itr.first<<" "<<itr.second.size()<<endl;
//                     if(itr.second.size()!=1){
//                         be=false;
//                         break;
//                     }

//                 }
                if(be)
                ans.push_back(words[i]);
            }
                
        }
        map<char,vector<char>>ma;
        
        return ans;
    }
};