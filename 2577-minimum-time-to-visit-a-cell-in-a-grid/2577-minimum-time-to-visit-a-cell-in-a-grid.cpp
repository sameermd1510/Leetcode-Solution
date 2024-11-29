using pii =pair< int,int>;
class Solution {
public:
    int r,c;
    int d[4][2]={{0,1}, {0,-1}, { 1,0},{-1,0}};
    
    bool valid( int x, int y){
        return min(x,y)>=0 && x<r && y<c;
    }
    int minimumTime(vector<vector<int>>& g) {
        r=g.size();
        c=g[0].size();
        
        vector< vector<int> > dp( r+1,vector< int>(c+1,INT_MAX-10000));
        dp[0][0]=0;
        
        bool fl=false;
        if(g[0][1]<=1 || g[1][0]<=1){
            fl=true;
        }
        if(!fl) return -1;
        
        priority_queue< pair< int,pii> , vector< pair< int,pii> > , greater< pair< int,pii>> > pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            
            auto it=pq.top();
            pq.pop();
            int t=it.first;
            int x=it.second.first  , y=it.second.second;
            
            if(x==r-1 && y==c-1) return t;
            for( int i=0;i<4;i++){
                int cx= x+d[i][0] ,cy= y+d[i][1];
                if(!valid(cx,cy)) continue;
                
                if(g[cx][cy]<=1+t  ){
                    if( dp[cx][cy] > dp[x][y]+1){
                        dp[cx][cy]=1+dp[x][y];
                        pq.push({1+t ,{cx,cy}});
                    }
                }
                else if(fl){
                    int new_time=g[cx][cy]-t;
                    
                    if(new_time%2==0){
                        new_time++;
                    }
                    // if(new_time==1){
                    //     new_time=3;
                    // }
                    new_time+=t;
                    
                    dp[cx][cy]=new_time;
                    pq.push({max(new_time,g[cx][cy]),{cx,cy}});
                }
            }
        }
        return -1;
    }
};