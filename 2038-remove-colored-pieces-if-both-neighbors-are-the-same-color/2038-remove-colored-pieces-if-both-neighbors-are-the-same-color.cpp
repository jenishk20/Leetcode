class Solution {
public:
    bool winnerOfGame(string colors) {
         
        int n=colors.size();
        int i;
        int c1=0,c2=0;
        
        for(i=1;i<n-1;i++)
        {
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A')
                c1++;
            else if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B')
                c2++;
        }
        
      
        return c1>c2;
    }
};