class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string s=to_string(n);
        sort(s.begin(),s.end());
        
        for(int i=0;i<30;i++)
        {
            int val=(1<<i);
            string temp=to_string(val);
            sort(temp.begin(),temp.end());
            if(temp==s)
                return 1;
        }
        return 0;
    }
    
};