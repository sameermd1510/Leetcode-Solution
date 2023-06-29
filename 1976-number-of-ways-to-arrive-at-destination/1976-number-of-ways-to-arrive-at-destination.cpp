class Solution {
public:
    int M = 1e9 + 7;
    #define ll long long
    #define pll pair<ll, ll>
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // adj list to store u -> { v, time }
        unordered_map<int, vector<pair<ll,ll>>> adj;
        
        for(auto& road: roads) {
            adj[road[0]].push_back({(ll)road[1], (ll)road[2]});
            adj[road[1]].push_back({(ll)road[0], (ll)road[2]});
        }
        
        // dp to store cost and count to reach to this node with this cost
        vector<pll> dp(n, {1e15, 0});
        dp[0] = {0, 1};
        
        // { time, node }
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});
        
        while(pq.size()) {
            auto curr = pq.top(); pq.pop();
            ll cost = curr.first;
            ll node = curr.second;
            
            for(auto& child: adj[node]) {
                ll next = child.first;
                ll wt = child.second;
                
                // if cost is greater pdate to new cost
                if(dp[next].first > wt + cost) {
                    dp[next] = {wt+cost, dp[node].second};
                    pq.push({ dp[next].first, next });
                }
                
                // else add the count of parent to child
                else if(dp[next].first == wt + cost) {
                    dp[next].second += dp[node].second;
                    dp[next].second %= M;
                }
            }
        }
        return (dp[n-1].second);
    }
};
/*using ll= long long;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& e) {
        
        int M=1e9+7;
        vector< pair< ll, ll> > ad[n];
        
        for( vector< int> x: e){
            ad[x[0]].push_back({x[1]*1LL,x[2]*1LL});
            ad[x[1]].push_back({x[0]*1LL,x[2]*1LL});
        }
        
        priority_queue< pair< ll,ll> , vector< pair< ll,ll>> , greater< pair<ll,ll>> > pq;
        vector< ll> dp(n,LLONG_MAX), w(n,0); 
        
        pq.push({0, 0});
        dp[0]=0;
        w[0]=1;
        
        while(!pq.empty()){
            
            int sc=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            
            
            for( auto [de ,ct]: ad[sc]){
                
                if( dp[de ] > wt+ ct){
                    
                    dp[de ]=wt+ct;
                    w[de]=w[sc];
                    
                    pq.push({dp[de] ,de});
                    
                }
                else if( dp[de]==wt+ct)  w[de]= (w[de]%M+w[sc]%M)%M;
            }
        }
        return w[n-1];
    }
};*/