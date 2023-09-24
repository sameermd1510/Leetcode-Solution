class Solution {
public:
    double champagneTower(int p , int qr, int qg) {
        
        vector< vector< double> > dp(101);
        
        for( int i=0;i<=100;i++){
            dp[i].resize(i+1,0.0);
        }
        dp[0][0]=(double)p;
        for( int i=0;i<=qr;i++){
            for( int j=0;j<=i;j++){
                double d=(dp[i][j]-1)/2.0;
                
                if(d >0){
                    dp[i+1][j]+=d;
                    dp[i+1][j+1]+=d;
                }
            }
        }
        return (double)min(1.0,dp[qr][qg]);
    }
};