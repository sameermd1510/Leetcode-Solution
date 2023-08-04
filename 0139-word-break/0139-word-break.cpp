class Solution {
public:
    bool dp[300+1]; 
    bool wordBreak(string s, vector<string>& wordDict) 
    {                  
        unordered_map<string, int> m;
        
        for(string w: wordDict)
        m[w]++;

        for(int i=0; i<s.size(); i++) 
        {
            dp[i] = (m.find(s.substr(0, i+1)) != m.end());
            
            if(dp[i]) continue;
            
            for(int j=i; j-1 >= max(0, i-20+1); j--)
            {
                string s_ji = s.substr(j, i-j+1);  

                dp[i] = (m.find(s_ji) != m.end()) && dp[j-1];
            
                if(dp[i]) break;
            }
        }
        return dp[s.size()-1];
    }
};