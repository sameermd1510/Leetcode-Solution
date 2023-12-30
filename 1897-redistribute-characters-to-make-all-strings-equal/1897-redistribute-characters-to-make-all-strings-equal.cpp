class Solution {
public:
    bool makeEqual(vector<string>& w) {
        
        if(w.size()==1) return 1;
        
        unordered_map< char, int> m;
        
        int x=-1;
        for( string s:w){
            for( char ch:s){
                m[ch]++;
            }
        }
        
        for( auto t:m){
            
          if(t.second % w.size() !=0) return false;
        }
        return true;
    }
};