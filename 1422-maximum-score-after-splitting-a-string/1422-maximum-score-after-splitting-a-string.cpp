class Solution {
public:
    int maxScore(string s) {
        
        int c_one=0, c_zero=0;
        int ans=0;
        
        for( char ch:s) if(ch=='1') c_one++;
        
        int c_onel=0;
        
        for( int i=0;i<s.size()-1 ; i++){
            
            if(s[i]=='0') c_zero++;
            else c_onel++;
            
            ans=max( ans , c_zero+ (c_one-c_onel));
        }
        return ans;
    }
};