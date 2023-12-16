class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size()) return 0;
        if(s==t) return 1;
        
        int m=0 ,n=0 , sm=0,tm=0;
        for( int i=0;i<s.size();i++){
            m=m ^ (1<<(s[i]-'a'));
            n=n ^ ( 1<<(t[i]-'a'));
            
            sm+=s[i]*s[i];
            tm+=t[i]*t[i];
        }
        return (m==n && sm==tm);
    }
};