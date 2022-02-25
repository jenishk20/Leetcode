// class Solution {
// public:
//     bool isAnagram(string s,string t)
//     {
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
//         return s==t;
//     }
//     vector<int> findAnagrams(string s, string p) {
        
//         vector<int>idx;
        
//         int n=s.size();
//         int m=p.size();
//         int i;
//         for(i=0;i<=n-m;i++)
//         {
//             string temp=s.substr(i,m);
//             if(isAnagram(temp,p))
//                 idx.push_back(i);
//         }
//         return idx;
        
//     }
// };

class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>idx;
        
        int n=s.size();
        int m=p.size();
        if(m>n)
            return idx;
        map<char,int>ma,ma1;
         vector<int>freq(26,0),freq1(26,0);
        for(auto i:p)
            freq[i-'a']++;

       
        int i;
 
        for(i=0;i<m;i++)
            freq1[s[i]-'a']++;
        for(i=m;i<n;i++)
        {
            
            if(freq==freq1)
                idx.push_back(i-m);
            
            freq1[s[i]-'a']++;
            freq1[s[i-m]-'a']--;
            
            
            
           
           
        
         
        }
          if(freq==freq1)
                idx.push_back(i-m);
        return idx;
        
    }
};