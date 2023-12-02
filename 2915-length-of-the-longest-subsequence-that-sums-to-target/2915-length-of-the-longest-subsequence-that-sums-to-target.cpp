class Solution {
public:
    int dp[1000+1][1000+1];
    int sol( vector< int> &a, int i, int sm ,int l, int s){
        if( s==sm) return 0;
        
        if(i >=a.size() || s > sm ) return INT_MIN;
        
        if(dp[i][s]!=-1) return dp[i][s]; 
        
        return dp[i][s]=max(1+sol(a,i+1,sm,l+1,s+a[i]) , sol(a,i+1,sm,l,s) );
        
    }
    int lengthOfLongestSubsequence(vector<int>& a, int sm) {
        
        memset(dp,-1,sizeof(dp));
        int ans=sol(a,0,sm,0,0);
        
        return ans > 0 ? ans :-1;
    }
};