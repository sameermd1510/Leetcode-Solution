struct Data
{
    int x,y,ans;
    Data(int i,int j,int an)
    {
        x=i;
        y=j;
        ans=an;
    }
};
class Solution {
public:
    int r,c;
    int dx[8][2]={ {1,0} ,{0,1},{-1,0},{0,-1},{ 1,1},{-1,1},{-1,-1},{1,-1}};
    bool valid(int i,int j)
    {
        return (i>=0 && i<r && j>=0 && j<c);
    }
    int bfs(vector< vector<int> > &g,vector< vector< bool> > &vis,int i,int j)
    {
        queue< Data> q;
        Data d={i,j,1};
        q.push(d);
        
        while(!q.empty())
        {
            d=q.front();
            q.pop();
            
            int x=d.x;
            int y=d.y;
            int ans=d.ans;
            
            vis[x][y]=true;
            
            if(x==r-1 && y==c-1 ) return ans;
            
            for(int i=0;i<8;i++)
            {
                int cx= x+dx[i][0];
                int cy= y+dx[i][1];
                if(valid(cx,cy) && g[cx][cy]==0 && !vis[cx][cy] )
                {
                    vis[cx][cy]=true;
                    q.push({cx,cy,ans+1});
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& g) 
    {
        r=g.size();
        c=g[0].size();
        
        if(g[0][0]==1 || g[r-1][c-1]==1) return -1;
        
        vector< vector< bool> > vis( r, vector<bool> (c,false));
        
        return bfs(g,vis,0,0);
        
    }
};