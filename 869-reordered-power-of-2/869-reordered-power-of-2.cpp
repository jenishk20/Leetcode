class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string s=to_string(n);
        sort(s.begin(),s.end());
        do
        {
            if(s[0]!='0'){
            int val=stoi(s);
                cout<<val<<endl;
            if((val&(val-1))==0)
            {
                return 1;
            }
            }
            
        }while(next_permutation(s.begin(),s.end()));
        return 0;
    }
    
};