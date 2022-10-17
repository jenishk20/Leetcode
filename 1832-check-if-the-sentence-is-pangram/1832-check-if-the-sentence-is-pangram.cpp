class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>ma;
        for(auto i:sentence)
            ma[i]++;
        return ma.size()==26;
    }
};