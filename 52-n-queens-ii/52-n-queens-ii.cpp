class Solution {
    
private:
    bool safe(int row,int col,int n,vector<string>&board)
    {
        int trow=row;
        int tcol=col;
        
        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            
            row--;
            col--;
        }
        row=trow;
        col=tcol;
        
        while(row<n and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            row++;
            col--;
        }
        
        row=trow;
        col=tcol;
        
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        return true;
        
        
        
    }
    void recur(vector<string>&board,vector<vector<string>>&ans,int n,int col)
    {
        
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(safe(i,col,n,board))
            {
                board[i][col]='Q';
                recur(board,ans,n,col+1);
                board[i][col]='.';
            }
        }
    }
public:
    int  totalNQueens(int n) {
        
        
        vector<vector<string>>ans;
        
        string s(n,'.');
        vector<string>board(n);
        for(int i=0;i<n;i++)
            board[i]=s;
        
        recur(board,ans,n,0);
        
        return ans.size();
    }
};