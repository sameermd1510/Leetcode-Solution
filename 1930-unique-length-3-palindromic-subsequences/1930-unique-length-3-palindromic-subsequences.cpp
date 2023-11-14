class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector< int> f(26,-1),l(26,-1);
        
        for( int i=0;i<s.size();i++){
            int in=s[i]-'a';
            if(f[in]==-1){
                f[in]=i;
            }
            l[in]=i;
        }
        int ans=0;
        for( int i=0;i<26;i++){
            if(f[i]==-1) continue;
            
            unordered_set<char> un;
            for( int j=f[i]+1; j < l[i]; j++) un.insert(s[j]);
            
            ans+=un.size();
            un.clear();
        }
        return ans;
    }
};