class SeatManager {
    
    private static TreeSet<Integer> s;
    private static int n;
    public SeatManager(int n) {
        this.n=n;
        this.s=new TreeSet<>();
        
        for( int i=1;i<=n;i++){s.add(i);};
    }
    
    public int reserve() {
        int vl=s.first();
        s.remove(vl);
        return vl;
    }
    
    public void unreserve(int seatNumber) {
        s.add(seatNumber);
        
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */