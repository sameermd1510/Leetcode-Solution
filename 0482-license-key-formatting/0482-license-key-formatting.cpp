class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans="";
        
        int cnt=0;
        reverse(s.begin(), s.end());
        
        for( char ch:s){
            if( (ch>='a' && ch<='z' ) || ( ch >='A' && ch<='Z') ) ch= ch & ~32;
                
            if( ch!='-' && cnt++ <k){
                ans+=ch;
            }
            else if(ch!='-' ){
                ans+="-";
                ans+=ch;
                cnt=1;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};