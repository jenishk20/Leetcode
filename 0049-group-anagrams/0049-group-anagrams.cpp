class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        vector<string>temp;
        map<string,vector<int>>ma;
        for(auto i:strs)
        {
            auto tt=i;
            sort(tt.begin(),tt.end());
            temp.push_back(tt);
        }
        for(int i=0;i<temp.size();i++)
        {
            ma[temp[i]].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:ma)
        {
            vector<string>res;
            for(auto it2:it.second)
            {
                res.push_back(strs[it2]);
            }
            ans.push_back(res);
        }
        return ans;
//         vector<map<char,int>>ve;
//         for(auto i:strs)
//         {
//             map<char,int>temp;
//             for(auto it:i)
//             {
//                 temp[it]++;
//             }
//             ve.push_back(temp);
//         }
//         map<map<char,int>,int>ma;
//         int st=0;
//         for(auto i:ve){
            
//             if(ma.find(i)==ma.end())
//             {
                
//             }
//             ma[i]++;
//         }
        
//         for(auto it:ma)
//         {
//             for(auto it1:it.first)
//             {
//                     cout<<it1.first<<" "<<it1.second<<endl;
//             }
//             cout<<it.second<<endl;
//         }
//         for(auto i:strs)
//         {
//             map<char,int>temp;
//             for(auto it:i)
//             {
//                 temp[it]++;
//             }
//             if(ma.find())
//         }
//         return {};
    }
};