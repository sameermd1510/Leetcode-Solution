class SeatManager {
public:
    SeatManager(int n) {
        N=n;
        us.clear();
        for( int i=1;i<=n;i++){
            us.insert(i);
        }
    }
    
    int reserve() {
        
        auto t=us.begin();
        int vl=*t;
        us.erase(vl);
        return vl;
    }
    
    void unreserve(int seatNumber) {
        us.insert(seatNumber);
    }
    private: 
        int N;
        set<int> us;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */