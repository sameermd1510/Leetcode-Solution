class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size()) return 0;
        if(s==t) return 1;
        
        int m=0,sm=0;
        for( int i=0;i<s.size();i++){
            m=m ^ (1<<(s[i]-'a'));
            m=m ^ ( 1<<(t[i]-'a'));
            
            sm+=s[i]*s[i];
            sm-=t[i]*t[i];
        }
        return (!m && !sm);
    }
};