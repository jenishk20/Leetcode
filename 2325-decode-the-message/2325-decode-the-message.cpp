class Solution {
public:
    string decodeMessage(string key, string message) {
        string res="";
        map<char,char>mappings;
        
        char ch='a';
        for(int i=0;i<key.size() and ch<='z';i++)
        {
            if(key[i]==' ')
                continue;
            else if(mappings.find(key[i])!=mappings.end())
            {
                continue;
            }
            else
            {
                mappings[key[i]]=ch++;
            }
        }
        for(int i=0;i<message.size();i++)
        {
            if(message[i]==' ')
                res+=' ';
            else
                res+=mappings[message[i]];
        }
        return res;
    }
};