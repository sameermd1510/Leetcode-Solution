class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        
        int r=m.size() ,c=m[0].size();
        vector < vector< int> > n(c);
        
        for( int i=0;i<c;i++){
            for( int j=0;j<r;j++){
                n[i].push_back(m[j][i]);
            }
        }
        return n;
        
    }
};
