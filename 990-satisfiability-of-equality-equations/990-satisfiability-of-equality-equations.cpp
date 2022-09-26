class Solution {
public:
    int find(int k,vector<int>&parent)
    {
        if(parent[k]==k)
            return k;
        return parent[k]=find(parent[k],parent);
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26,0);
        int i;
        for(i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(auto i:equations)
        {
            if(i[1]=='=')
            {
                int p1=find(i[0]-'a',parent);
                int p2=find(i[3]-'a',parent);
                cout<<i[0]<<" "<<i[3]<<endl;
                if(p1!=p2)
                {
                    cout<<p1<<' '<<p2<<endl;
                    parent[p1]=p2;
                }
            }
        }
        for(auto i:equations)
        {
            if(i[1]=='!')
            {
                int p1=find(i[0]-'a',parent);
                int p2=find(i[3]-'a',parent);
                //cout<<i[0]<<" "<<i[3]<<endl;
                if(p1==p2)
                {
                    return  false;
                    // cout<<p1<<' '<<p2<<endl;
                    // parent[i[0]-'a']=i[1]-'a';
                }
            }
        }
        return true;
    }
};