class Solution {
public:
    string destCity(vector<vector<string>>& p) {
        unordered_set< string> s;
        for( int i=0; i<p.size();i++)  s.insert(p[i][0]);
        
        for( int i=0;i<p.size() ;i++)  if( !s.count(p[i][1])) return p[i][1];
        
        return "";
        
    }
};