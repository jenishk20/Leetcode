class Solution {
public:
    bool digitCount(string num) {
        map<int,int>ma;
        
        for(auto i:num)
        {
            ma[i-'0']++;
        }
        for(int i=0;i<num.size();i++)
        {
            if(ma[i]!=num[i]-'0')
                return false;
        }
        return true;
    }
};