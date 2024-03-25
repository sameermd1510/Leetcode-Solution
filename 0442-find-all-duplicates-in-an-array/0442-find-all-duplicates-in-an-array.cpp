class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        unordered_map< int, bool> m;
        vector< int> ans;
        for( int x:a){
            if( m.find(x)!=m.end()) ans.push_back(x);
            else m[x]=1;
        }
        return ans;
    }
};