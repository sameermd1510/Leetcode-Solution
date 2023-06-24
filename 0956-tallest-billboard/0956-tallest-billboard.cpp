#define  fi                first
#define  se                second
class Solution {
public:
    
    int tallestBillboard(vector<int>& a) {
        int n=a.size();
        int s=0;
        for( int i:a) s+=i;
        
        unordered_map< int, int> dp;
        dp[0]=0;
        
        // mis dp[ diffi.e(taller-shorter)]=taller.
        for( int x:a){
            
            unordered_map< int, int> n=dp;
            
            for( auto t:n){
                int d=t.fi ;
                
                dp[d+x]=max(dp[d+x] ,n[d] );
                
                dp[abs(d-x)]=max( dp[abs(d-x)] , n[d]+min(d,x));
            }
        }
        return dp[0];
    }
};