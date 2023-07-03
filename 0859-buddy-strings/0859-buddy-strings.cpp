class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size() ) return 0;
        
        int i=0,j=0,c=0;
        
        int f[26]={};
        
        for( char ch:s) {
            f[ch-'a']++;
            if(f[ch-'a']>1) c=1;
        }
        
        if(s==g ) return c;
        for( ;i<s.size();i++){
            if(s[i]==g[j]){
                j++;
            }
            else break; 
        }
        int k=i;
        i++;
        j++;
        for( ;i<g.size();i++){
            if(s[i]==g[j]){
                j++;
            }
            else break;
        }
        swap(s[k],s[i]);
        cout<<s<<"\n";
        return s==g ;
    }
};