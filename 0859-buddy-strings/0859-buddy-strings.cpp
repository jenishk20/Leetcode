class Solution {
public:
    bool buddyStrings(string s, string goal) {
        set<char>swaps;
        
        int n= s.size();
        int m = goal.size();
        if(n!=m)
            return false;
        
        if(s==goal)
            if(set<char>(s.begin(),s.end()).size()<n)
                return true;
        
        vector<int>diff;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!=goal[i])
                diff.push_back(i);
        }
        for(auto i:diff)
            cout<<i<<endl;
        //cout<<diff.size()<<endl;
        return diff.size()==2 and s[diff[0]]==goal[diff[1]] and
            s[diff[1]]==goal[diff[0]];

    }
};