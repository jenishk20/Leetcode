#define ll long long
class ATM {
public:
    map<ll,ll>ma;
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        int st=0;
        for(auto i:banknotesCount)
        {
            if(st==0)
                ma[20]+=i;
            else if(st==1)
                ma[50]+=i;
            else if(st==2)
                ma[100]+=i;
            else if(st==3)
                ma[200]+=i;
            else 
                ma[500]+=i;
            st++;
        }
        
    }
    
    vector<int> withdraw(int amount) {
        
        vector<int>ans;
        vector<pair<ll,ll>>deno;
        for(auto i:ma)
            deno.push_back(i);
        
        sort(deno.begin(),deno.end());
      
        int n=deno.size();
        int i;
        map<ll,ll>used;
        for(i=n-1;i>=0;i--)
        {
            if(amount==0)
                break;
            ll freq=deno[i].second;
            ll note=deno[i].first;
            if(amount<note or freq==0)
                continue;
            int j;
            
            ll req=amount/note;
            ll kk=min(req,freq);
            amount-=kk*note;
            used[note]+=kk;
        }
        if(amount!=0)
            return {-1};
        
        for(auto i:used)
        {
            ma[i.first]-=i.second;
           // cout<<i.first<<" "<<i.second<<endl;
        }
        
        map<ll,ll>tt;
        tt[20]=0;
        tt[50]=0;
        tt[100]=0;
        tt[200]=0;
        tt[500]=0;
        for(auto i:used)
            tt[i.first]+=i.second;
        for(auto i:tt)
            ans.push_back(i.second);
        return  ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */