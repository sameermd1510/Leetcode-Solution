class Solution {
public:
    
    void dfs( int i, int j, vector< vector< char> >& m){
        
        if( i>=m.size() || j>= m[0].size() || i<0 || j<0 || m[i][j]!='1') return ;
        
        m[i][j]='0';
        
        dfs( i+1 , j , m);
        dfs(i-1 , j , m);
        dfs( i, j+1 , m);
        dfs( i, j-1,m);
    }
    int numIslands(vector<vector<char>>& m) {
        int count=0;
        for( int i=0;i < m.size() ; i++){
            
            for( int j =0 ; j< m[0].size();j++){
                
                if( m[i][j]=='1'){
                    dfs(i,j,m);
                    count++;
                }
            }
        }
        return count;
    }
};