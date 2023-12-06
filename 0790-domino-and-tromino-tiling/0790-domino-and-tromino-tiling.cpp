#define ll long long
ll dp[1001];
class Solution {
public:
    int numTilings(int n) {
        
        ll m=1e9+7;
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        
        for( int i=4;i<=n;i++){
            dp[i]=( (2*dp[i-1]%m )%m + dp[i-3]%m )%m;
        }
        
        
        return dp[n];
    }
};