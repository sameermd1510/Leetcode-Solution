class Solution {
public:
    
    // 1 2 3 4  
    int M=1e9+7;
    int dp[31][1000+1];
    int sol( int n,int k, int t){
        
        int ans=0;
        if( t==0 && n==0){
            return 1;
        }
        if( n<=0 || t<0) return 0;
        
        if(dp[n][t]!=-1) return dp[n][t];
        for( int i=1;i<=k;i++){
            if( i <=t )
            ans=( ans % M + sol( n-1,k,t-i)%M)%M;
        }
        return dp[n][t]=ans;
    }
    
    int numRollsToTarget(int n, int k, int t) {
//         int dp[n+1][t+1];
        
//         for( int i=0;i<=t;i++){
//             dp[0][i]=0;
//         }
//         for( int i=1;i<=n;i++){
//             dp[i][0]= 0;
//         }
        memset(dp,-1,sizeof(dp));
        return sol( n,k,t);
    }
};