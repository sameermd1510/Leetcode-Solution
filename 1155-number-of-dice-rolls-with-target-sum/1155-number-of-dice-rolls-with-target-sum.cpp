class Solution {
public:
    
    // 1 2 3 4  
    int M=1e9+7;
//     int dp[31][1000+1];
//     int sol( int n,int k, int t){
        
//         int ans=0;
//         if( t==0 && n==0){
//             return 1;
//         }
//         if( n<=0 || t<0) return 0;
        
//         if(dp[n][t]!=-1) return dp[n][t];
//         for( int i=1;i<=k;i++){
//             if( i <=t )
//             ans=( ans % M + sol( n-1,k,t-i)%M)%M;
//         }
//         return dp[n][t]=ans;
//     }
    
    int numRollsToTarget(int n, int k, int t) {
        vector< vector< int> > dp( n+1, vector< int>(t+1,0));
        
        dp[0][0]=1;
        for( int i=1;i<=n;i++){
            for( int s=1;s<=t;s++){
                int x=0;
                for( int j=1;j<=k;j++){
                    if( j<=s ) x=(x %M+dp[i-1][s-j] %M)%M;
                }
                dp[i][s]=x;
            }
        }
        return dp[n][t];
    }
};