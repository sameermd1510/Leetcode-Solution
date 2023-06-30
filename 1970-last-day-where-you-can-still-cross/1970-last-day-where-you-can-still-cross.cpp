class Solution {
public:
    int d[4][2]={{0,1} , { 1,0},{0,-1},{-1,0}};
    int r,c;
    bool valid(int x,int y){
        return min(x,y)>=0  && x<r && y<c;
    }

    bool sol(vector< vector< int> >& p, int Mid){
        vector<vector<int> > m(r, vector<int>(c, 0));
        
        for (int i = 0; i < Mid; ++i) m[p[i][0]-1][p[i][1]-1] = 1;
        
        queue< pair< int,int> > q;
        for( int i=0;i<c;i++){
            if(m[0][i]==0) {
                q.push({0,i});
                m[0][i]=1;
            }
        }
        
        while( !q.empty()){
            auto t=q.front();q.pop();
            int x=t.first , y=t.second;
            
            if(x==r-1) return true;
            
            for( int i=0;i<4;i++){
                int xn=x+d[i][0] , yn=y+d[i][1];
                
                if( valid(xn,yn) && m[xn][yn]!=1){
                    q.push({xn,yn});
                    m[xn][yn]=1;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int R, int C, vector<vector<int>>& p) {
        int ans=0;
        int lb=1,rb=p.size();
        r=R,c=C;
        while( lb<=rb){
            int m=lb+(rb-lb)/2;
            
            if(sol(p,m) ){
                ans=m;
                lb=m+1;
            } else rb=m-1;
        }
        return ans;
    }
};