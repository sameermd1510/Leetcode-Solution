class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& rs, vector<vector<string>>& p) {
        int n = rs.size();
        
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n); // reserve space and avoid hash collisions
        dp[0] = {};
        
        unordered_map<string, int> m; // to store skills with index.
        for (int i=0;i<n;i++) m[rs[i]] = i;
        
        for (int i = 0; i < p.size(); ++i) {
            int cur_skill = 0;
            
            for (auto& skill: p[i]) 
                cur_skill |= 1 << m[skill];
            
            for( auto t:dp){
                int comb=t.first | cur_skill;
                
                if(!dp.count(comb) || dp[comb].size()>1+dp[t.first].size()){
                    dp[comb]=t.second;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};