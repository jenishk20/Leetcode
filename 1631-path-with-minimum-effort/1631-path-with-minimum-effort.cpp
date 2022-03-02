class Solution {
private:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int r=heights.size();
        int c=heights[0].size();
        int i,j;
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        vector<vector<int>>distance(r,vector<int>(c,INT_MAX));
        distance[0][0]=0;
        
        while(!pq.empty())
        {
            int x=pq.top()[0];
            int y=pq.top()[1];
            int have=pq.top()[2];
            pq.pop();
            for(int k=0;k<4;k++)
            {
                int nx=dx[k]+x;
                int ny=dy[k]+y;
                if(nx>=0 and ny>=0 and nx<r and ny<c)
                {
                    int newDistance=abs(heights[nx][ny]-heights[x][y]);
                    
                    if(distance[nx][ny]>max(newDistance,have))
                    {
                        distance[nx][ny]=max(newDistance,have);
                        pq.push({nx,ny,distance[nx][ny]});
                    }
                    
                }
            }
        }
        return distance[r-1][c-1];
    }
};