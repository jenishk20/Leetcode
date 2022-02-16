class Solution {
public:
    int minSteps(string s, string t) {
          
        map<char,int>ma,ma1;
        for(auto i:s)
            ma[i]++;
        
//         for(auto i:ma)
//             cout<<i.first<<" "<<i.second<<endl;
        for(auto i:t)
            ma[i]--;
        int count=0;
           // for(auto i:ma)
           //  cout<<i.first<<" "<<i.second<<endl;
        for(auto i:ma)
        {
            if(i.second<0)
                count+=abs(i.second);
        }
        return count;
       
    }
};