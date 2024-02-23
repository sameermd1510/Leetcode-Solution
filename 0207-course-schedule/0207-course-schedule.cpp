class Solution {
public:
    unordered_map< int, vector< int> > adj;
    
    
    bool dfs(  int i,vector< int>& vis){
        
        if( vis[i]==1) return true;
        
        if( vis[i]==0){
            vis[i]=1;
            for( int x: adj[i]){
                if( dfs( x,vis)) return true;
            }
        }
        vis[i]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        
        for( vector< int> x: p){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        for( int i=0;i<n;i++){
            if(dfs(i, vis)) return false;
        }
        return true;
        
    }
};