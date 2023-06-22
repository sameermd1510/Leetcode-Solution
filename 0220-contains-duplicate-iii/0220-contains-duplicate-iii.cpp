class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int id, int vd) {
        
        set< int> s;
        for( int i=0;i<a.size();i++){
        
            if( i>id) s.erase(a[i-id-1]);
            
            auto t=s.lower_bound(a[i]-vd);
            if(t!=s.end() && *t-a[i]<=vd) return true;
            s.insert(a[i]);
        }
        return false;
    }
};