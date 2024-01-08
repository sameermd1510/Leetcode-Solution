class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &a) {
        int n = a.size();
        int ans = 0;
        vector< unordered_map<long long, int> >dp(n); // dp[i][d]
        for (int i = 1; i < n; i++) {
            for (int j =0 ; j < i; j++) {
                long long diff = a[i]*1LL - a[j];
                
                int cnt =( dp[j].find( diff)!=dp[j].end()) ? dp[j][diff] :0;;
                dp[i][diff] += cnt + 1;
                ans += cnt;
            }
        }
        return ans;
    }
};