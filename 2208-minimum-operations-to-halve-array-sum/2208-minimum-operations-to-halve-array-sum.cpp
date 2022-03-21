class Solution {
public:
    int halveArray(vector<int>& nums) {
            
        double sum=0;
        priority_queue<double>pq;
        for(auto i:nums)
        {
            pq.push(i);
            sum+=i;
        }
        int c=0;
        double req=sum/2.0;
        while(!pq.empty())
        {
            if(sum<=req)
                break;
            double curr=pq.top();
            pq.pop();
            c++;
            
            double res=curr/2.0;
            pq.push(res);
            sum-=res;
          //  cout<<sum<<" "<<c<<endl;
            
        }
        return c;
    }
};