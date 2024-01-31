class Solution {
public:
    int r , c;
    int dp[72][72][72];
    int m[3]={-1,0,1};
    
    bool check( int c1, int c2, int R){
        return ( min( c1,c2)>=0 && max( c1,c2)<c && R<r ); 
    }
    
    int sol( int c1, int c2,int R , vector<vector<int>>& g  ){
        
        if( !check( c1,c2,R) || R==r ) return 0;
        
        if( dp[R][c1][c2]!=-1) return dp[R][c1][c2]; 
        int ans=INT_MIN;
        for( int i=0;i<3;i++){
            for( int j=0;j<3;j++){
                int cn1=c1+m[i];
                int cn2=c2+m[j];
                ans=max(ans , sol( cn1 ,cn2 , R+1 , g) );
            }
        }
        ans += (c1 == c2) ? g[R][c1] : g[R][c1] + g[R][c2];
        return dp[R][c1][c2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& g) {
        r=g.size() ;
        c= g[0].size();
        memset( dp,-1,sizeof(dp));
        return sol( 0,c-1, 0,g);
    }
};