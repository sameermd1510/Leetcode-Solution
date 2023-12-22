class RecentCounter {
public:
    
    vector< int> a;
    RecentCounter() {
        
    }
    
    int ping(int x) {
        a.push_back(x);
        int d=a.end()-lower_bound(a.begin(),a.end(), x-3000);
        return d;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */