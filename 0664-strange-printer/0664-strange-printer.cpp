class Solution {
public:
    int strangePrinter(string s) {
        s.erase(unique(s.begin(),s.end()),s.end());
        
        int n=s.size();
        vector< vector< int>> dp( n, vector< int> (n,n));
        
        for( int i=0;i<n;i++){
            dp[i][i]=1;
            
            if(i+1<n ) dp[i][i+1]=2-(s[i]==s[i+1]);
        }
        
        for( int l=2;l<=n;l++){
            for( int st=0;st+l<n;st++){
                int e=l+st;
                for( int k=st;k<e;k++){
                    dp[st][e]=min( dp[st][e]  ,  dp[st][k]+dp[k+1][e]-(s[st]==s[e]));
                }
            }
        }
        return dp[0][n-1];
        
    }
};