class Solution {
public:
    bool check( const string a, const string b){
        if(a.size()==b.size()){
            int c=0;
            for( int i=0; i<a.size();i++){
                if(a[i]!=b[i]) c++;
            }
            return c==1;
        }
        return 0;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& w, vector<int>& g) {
        
        vector< vector< string> > dp(n);
        for( int i=0;i<n;i++){
            dp[i].push_back(w[i]);
        }
        
        int ml=1;
        for( int i=1;i<n;i++){
            for( int j=0;j<i;j++){
                if(g[i]!=g[j] && check(w[i],w[j]) && dp[i].size() < dp[j].size()+1 ){
                    dp[i]=dp[j];
                    dp[i].push_back(w[i]);
                    ml=max(ml,(int)dp[i].size());
                }
            }
        }
        for( int i=0;i<n;i++){
            if(dp[i].size()==ml){
                return dp[i];
            }
        }
        return dp[0];
    }
};