class Solution {
public:
    string largestPalindromic(string num) {
        
        int n=num.size();
        map<int,int>ma;
        for(auto i:num)
            ma[i]++;
        
        sort(num.begin(),num.end());
        reverse(num.begin(),num.end());
        string begin="";
        string mid="";
        string end="";
        
        int prev=0;
        for(auto i:num)
        {
            if(ma[i]&1)
            {
                int curr=i-'0';
                if(curr>=prev)
                {
                    mid=i;
                    prev=curr;
                }
                ma[i]--;
            }
            else
            {
                int k=ma[i]/2;
                while(k--)
                {
                    begin+=i;
                    end+=i;
                }
                ma[i]=0;
            }
        }
        
        cout<<begin<<" "<<mid<<" "<<end<<endl;
        
        int i;
        for( i=0;i<begin.size();i++)
        {
            if(begin[i]!='0')
                break;
        }
        begin=begin.substr(i);
        
        for( i=0;i<end.size();i++)
        {
            if(end[i]!='0')
                break;
        }
        end=end.substr(i);
        
        reverse(end.begin(),end.end());
        
        if(begin.size()==0 and mid.size()==0
           and end.size()==0)
            return "0";
        
        return begin+mid+end;
        
        
        
    }
};