class Solution {
public:
    int r,c;
    int dp[200][200]; 
    
    //program to calculate mac Rectangle in Histogram.
    int maxhistogram( int i){ 
        
        stack< int> s;
        int ans=0;  
        int j=0;
        while( j< c){   
            if( s.empty() || dp[i][ s.top()] <= dp[i][j]) s.push(j++);
            else{
                int t=s.top();
                s.pop();
                ans= max( ans, dp[i][t]* ( (s.empty()) ?j : ( j-s.top()-1) ));
            }
        }
        while( !s.empty()){
            int t=s.top();
            s.pop();  
            ans= max( ans, dp[i][t]* ( (s.empty()) ?j : ( j-s.top()-1) ));   
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& m) {
        r=m.size();
        c=m[0].size();
        
        for( int i=0;i<c;i++) dp[0][i]=( m[0][i]=='1') ? 1:0;
        
        int Ans=maxhistogram(0);
        
        for( int i=1;i<r;i++){
            for( int j=0;j<c;j++){
                if( m[i][j]=='1') dp[i][j] =1+ dp[i-1][j];
            }
            Ans=max( Ans, maxhistogram(i));   
        }
        return Ans;
    }
};