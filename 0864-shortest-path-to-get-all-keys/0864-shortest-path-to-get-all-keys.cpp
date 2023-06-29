/*class Solution {
public:
    int r,c;
    int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int dp[35][35];
    bool valid( int x,int y){
        return min(x,y)>=0 && x<r && y<c;
    }
    int shortestPathAllKeys(vector<string>& g) {
        
        
        queue< pair< int,int> > q;
        int k=0;
        
        unordered_map< char, bool > f;
        
        r=g.size() ,c=g[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]=='@') {
                    q.push({i,j});
                    vis[i][j]=1
                }
                else if( g[i][j]>='a' && g[i][j]<='z'){
                    k++;
                    f[g[i][j]]=1;
                }
            }
        }
        
        while( !q.empty()){
            auto t=q.front();
            int x=t.first, y=t.second;
            
            for( int i=0;i<4;i++){
                int xn=x+d[i][0] , yn=y+d[i][1];
                if(dp)
            }
        }
        
    }
};*/
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        unordered_map<char,int>key_bit;
        int bit_start=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(islower(grid[i][j])){
                    key_bit[grid[i][j]]=bit_start++;
                }
            }
        }

        int mask_end = (1<<bit_start) -1;
        int mask_size = (1<<bit_start);

        vector<vector<vector<bool>>>memo(m,vector<vector<bool>>(n,vector<bool>(mask_size,false)));

        vector<int>start;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    start={i,j,0} ;
                }
            }
        }

        queue<vector<int>>q;
        q.push(start);
        int step=0;

        while(!q.empty()){
            int sz=q.size();

            for(int k=0;k<sz;k++){
                int row= q.front()[0];
                int col=q.front()[1];
                int mask=q.front()[2];
                q.pop();

                if(row<0 || row>=m || col<0 || col>=n) continue;

                if(grid[row][col]=='#') continue;

                if(isupper(grid[row][col])){
                    if((mask & (1 << key_bit[tolower(grid[row][col])]))==0) continue;
                }

                if(islower(grid[row][col])){
                    mask= mask | (1<<key_bit[grid[row][col]]);
                }

                if(mask==mask_end) return step;

                if(memo[row][col][mask]) continue;

                memo[row][col][mask]=true;

                q.push({row+1,col,mask});
                q.push({row-1,col,mask});
                q.push({row,col+1,mask});
                q.push({row,col-1,mask});
            }
            step++;
        }
        return -1;
    }
};