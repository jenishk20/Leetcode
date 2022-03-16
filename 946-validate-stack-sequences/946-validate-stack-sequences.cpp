class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int  n=pushed.size();
        stack<int>se;
        map<int,int>ma;
        int i,j;
        j=0;
        for(i=0;i<n;i++)
        {
            int toPop=popped[i];
            // cout<<toPop<<" "<<ma[toPop]<<endl;
            if(ma[toPop])
            {
                //cout<<se.top()<<" "<<toPop<<endl;
                if(se.top()==toPop)
                    se.pop();
                else
                    return false;
                
                continue;
                    
            }
            while(j<n)
            {
                if(pushed[j]==toPop){
                    j++;
                    break;
                }

                ma[pushed[j]]=1;
                se.push(pushed[j]);
                j++;
            }
           // cout<<j<<endl;
            
            
        }
        return true;
    }
};