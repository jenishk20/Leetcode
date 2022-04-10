class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int>se;
        for(auto i:ops)
        {
            if(i=="+")
            {
                int op1=se.top();
                se.pop();
                int op2=se.top();
               
                se.push(op1);
                
                se.push(op1+op2);
            }
            else if(i=="C")
            {
               // cout<<"C\n";
                se.pop();
            }
            else if(i=="D")
            {
               
                se.push(se.top()*2);
            }
            else
            {
                
               // cout<<i<<endl;
                se.push(stoi(i));
                
            }
        }
        int sum=0;
        while(!se.empty())
        {
            sum+=se.top();
            se.pop();
        }
        return sum;
    }
};