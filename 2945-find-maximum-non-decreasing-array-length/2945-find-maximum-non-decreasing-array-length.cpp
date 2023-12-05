class Solution {
public:
    
    /*
    
    // 4 3 2 6-> 4 7 9 15 
    // 
    int findMaximumLength(vector<int>& A) {
        int n = A.size();
        vector<int> last(n + 1, 0);
        vector<int> acc(1, 0);
        vector<int> dp(n + 1, 0);
        
        int inf =INT_MAX;
        
        for (int j = 0; j < n; ++j) {
            int a = A[j];
            acc.push_back(a + acc.back());
            int i = j;
            while (last[i] > acc.back() - acc[i]) {
                --i;
            }
            last[j + 1] = acc.back() - acc[i];
            dp[j + 1] = dp[i] + 1;
        }
        return dp.back();
    }
    */
    int findMaximumLength(vector<int>& A) {
        int n = A.size();
        vector<int> pre(n + 2), dp(n + 1);
        vector<long long> acc(n + 1);
        for (int i = 1; i <= n; i ++) {
            acc[i] = acc[i - 1] + A[i - 1];
        }
        for (int i = 0, j = 1; j <= n; j++) {
            i = max(i, pre[j]); // if this was previously optimizesd.
            dp[j] = dp[i] + 1;
            int k = lower_bound(acc.begin(), acc.end(), 2 * acc[j] - acc[i]) - acc.begin();
            pre[k] = j;
        }
        return dp[n];
    }
};