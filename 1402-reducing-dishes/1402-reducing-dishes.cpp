class Solution {
public:
    int dp[502][503];
    int sol( int i, vector< int>& ss, int t){
        if(i>=ss.size() ) return 0;
        
        if(dp[i][t]!=-1) return dp[i][t];
        
        return dp[i][t]=max( ss[i]*t+sol(i+1,ss,t+1) , sol( i+1, ss,t));
        
    }
    int maxSatisfaction(vector<int>& ss) {
        memset(dp,-1,sizeof(dp));
        sort(ss.begin(),ss.end());
        return sol(0,ss,1);
    }
};