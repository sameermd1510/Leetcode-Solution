class MyHashSet {

    private int a[];
    public MyHashSet() {
        a=new int[1000000 /32+1];
    }
    
    public void add(int key) {
        a[idx(key)] |=getmask(key);
    }
    
    public void remove(int key) {
        a[idx(key)] &= ~(getmask(key));
    }
    
    public boolean contains(int key) {
        
        return (a[idx(key)] & getmask(key))!=0;
        
    }
    public static int idx( int key){
        return key/32;
    }
    public static int getmask( int key){
        key%=32;
        return 1<<key;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */