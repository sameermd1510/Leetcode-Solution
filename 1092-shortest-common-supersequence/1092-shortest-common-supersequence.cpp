class Solution {
public:
   string shortestCommonSupersequence(string a, string b) {
    int dp[1001][1001] = {}, m = a.size(), n = b.size();
    for (int i = 0; i < m; ++i) // DP
        for (int j = 0; j < n; ++j)
            dp[i + 1][j + 1] = a[i] == b[j] ? 
                dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
    string res;
    while (m && n) // Backtracking
        if (dp[m][n] == dp[m - 1][n])
            res += a[--m]; // Character only in a
        else if (dp[m][n] == dp[m][n - 1])
            res += b[--n]; // Character only in b
        else
            res += min(a[--m], b[--n]); // Shared character in a & b
    return a.substr(0, m) + b.substr(0, n) + string(rbegin(res), rend(res));
}
};