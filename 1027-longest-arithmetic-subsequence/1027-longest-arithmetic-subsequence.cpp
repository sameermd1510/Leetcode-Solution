class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        
        int res=2,n=a.size();
        vector< vector< int>> dp(n,vector< int> (2000,0));
        
        
        for( int i=0;i<n-1;i++){
            for( int j=i+1;j<n;j++){
                int d=a[j]-a[i]+1000;
                
                dp[j][d]=max(2,dp[i][d]+1);
                res=max(res, dp[j][d]);
            }
        }
        return res;
    }
};