class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& sp, int st, int en) {
        
        vector<pair< int, double> > adj[n];
        vector< double> ans( n,0.0);
        queue< int> q;
        
        int c=0;
        for( vector< int> x:e){
            adj[x[0]].push_back({x[1],sp[c]});
            adj[x[1]].push_back({x[0],sp[c++]});
        }
        
        ans[st]=1.0;
        q.push(st);
        
        while( !q.empty()){
            
            int in=q.front();
            q.pop();
            
            for( auto x:adj[in]){
                if(ans[x.first] < x.second *ans[in]){
                    q.push(x.first);
                    ans[x.first]=ans[in]*x.second;
                }
            }
        }
        return ans[en];
    }
};