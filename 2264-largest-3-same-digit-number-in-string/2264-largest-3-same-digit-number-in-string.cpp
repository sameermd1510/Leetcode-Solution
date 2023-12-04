class Solution {
public:
    string largestGoodInteger(string s) {
        
        string ans="";
        
        for( int i=2;i<s.size();i++){
            if(s[i]==s[i-1] && s[i]==s[i-2]){
                if(ans=="" || s[i]-'0' > ans[0]-'0'){
                    ans=s.substr(i-2,3);
                }
            }
        }
        return ans;
    }
};