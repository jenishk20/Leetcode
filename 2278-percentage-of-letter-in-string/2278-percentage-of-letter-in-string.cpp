class Solution {
public:
    int percentageLetter(string s, char letter) {
        
        int c=0;
        int n=s.size();
        for(auto i:s)
        {
            if(i==letter)
                c++;
        }
        return (c*100)/n;
    }
};