class Solution {
public:
    int countCharacters(vector<string>& a, string s) {
        int ans=0;
        
        int f[26]={0};
        for( char ch:s) f[ch-'a']++;
        
        for( string x:a){
            
            int c[26]={0};
            for( char ch:x){
                c[ch-'a']++;
            }
            int fl=1;
            for( int i=0;i<26;i++){
                if( c[i] > f[i]){
                    fl=0;
                    break;
                }
            }
            if(fl) ans+=x.size();
        }
        return ans;
    }
};