class Solution {
    
private:
    map<char,int>ma;
   static bool comp(char c1,char c2)
    {
       //cout<<ma[c1];
       return 1;
    }
public:
    // map<char,int>ma;
    // static bool comp(char c1,char c2)
    // {
    //     return ma[c1]<ma[c2];
    // }
    string customSortString(string order, string s) {
     
        int k=1;
        for(auto i:order)
            ma[i]=k++;
        // for(auto i:ma)
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        sort(s.begin(),s.end(),[&](char c1,char c2){
            return ma[c1]<ma[c2];
        });
        return s;
    }
};