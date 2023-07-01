class Solution {
public:
    int n,ans=INT_MAX;
    void solve( vector<int> &a, int k, int in,vector< int> &dp){
        
        if(in==n){
            ans=min(ans, *max_element(dp.begin(),dp.end()));
            return ;
        }
        for( int i=0;i<k;i++){
            dp[i]+=a[in];
            solve(a,k,in+1,dp);
            dp[i]-=a[in];
        }
    }
    int distributeCookies(vector<int>& a, int k) {
        n=a.size();
        vector<int> dp( k,0);
        solve(a,k,0,dp);
        return ans;
    }
};