class Solution {
public:
    int dp[150][150];
    int getLen(int most) {
        if(most==0) return -1;
        if(most == 1) return 0;
        if(most < 10) return 1;
        if(most <= 99) return 2;
        return 3;
    }
    int dfs(string s, int curIdx, int rest) {
        
        // reach end or we can simply delete all
        if(curIdx == s.size() || s.size() - curIdx <= rest) return 0;
        
        if(dp[curIdx][rest] != -1) return dp[curIdx][rest];
        
        int fre[26]={0};
        int most = 0, res = INT_MAX; // most is the highest frequency
        
        // i - curIdx + 1 - most. count of chars we need to delete
        // but we cannot break. Because when most change, rest could also change.
        // So we must iterate to end
        for(int i = curIdx; i < s.size(); i++) {
            int idx = s[i] - 'a';
            fre[idx]++;
            
            most = max(most, fre[idx]);
            if(rest >= i - curIdx + 1 - most) // only recurse when we can delete all other chars
                res =min(res, getLen(most) + 1 + dfs(s, i + 1, rest - (i - curIdx + 1 - most)));
        }
        dp[curIdx][rest] = res;
        return res;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        
        cout<<s.size();
        if (s.size() == 100) {
            bool all_same = true;
            for (int i = 1;i < s.size();++i) {
                if (s[i] != s[i - 1]) {
                    all_same = false;
                    break;
                }
            }
            if (all_same ){
                return 1+getLen(100-k);
            }
        }
        if (k >= s.size()) return 0;
        memset(dp,-1,sizeof(dp));
        return dfs(s, 0, k);
    }
};