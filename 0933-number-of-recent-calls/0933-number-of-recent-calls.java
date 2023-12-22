class RecentCounter {
    
    static int lower_bound(List<Integer> l, int key){
        
        int lb=0,ub=l.size()-1;
        
        while( lb<ub){
            int m=lb+(ub-lb)/2;
            
            if( l.get(m) <key){
                lb=m+1;
            }
            else ub=m;
            
        }
        
        while( lb>0 && l.get(lb)==key) lb--;
        
        return (l.get(lb) >=key) ? lb:lb+1;
    }
    List<Integer> a;
    public RecentCounter() {
        a=new ArrayList<>();
    }
    
    public int ping(int x) {
        a.add(x); 
        int l=a.size()-lower_bound(a , x-3000);
        return l;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */