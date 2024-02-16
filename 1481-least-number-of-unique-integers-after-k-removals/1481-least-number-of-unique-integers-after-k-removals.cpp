class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        
        unordered_map< int, int > hm;
        multiset< int> s;
        for( int x:a){
            hm[x]++;
        }
        
        for( auto t:hm){
            s.insert(t.second);
        }
        int c=0;
        for( auto t:s){
            if( k >=t){
                k=k-t;
                c++;
            }
            else return s.size()-c;
        }
        return s.size()-c;
    }
};