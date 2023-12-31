class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        unordered_map< char , int> m;
        int f[26]={0};
        int ans=0;
        
        for( int i=0; i<s.size() ;i++){
            if(m.count(s[i]))
            m[s[i]]=min( m[s[i]], i);
            else m[s[i]]=i;
        }
        for( int i=s.size()-1;i>=0;i--){
            ans=max( ans , i-m[s[i]]);
        }
        return ans-1;
    }
};