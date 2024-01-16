class RandomizedSet {
private:
    unordered_map< int,int> m;
    vector< int> a;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if( m.count(val) ) return false;
        
        m[val]=a.size();
        a.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if( !m.count(val) ) return false;
        
        int in=m[val];

        a[in]=a.back();
        
        m[ a.back()]=in;
        a.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        
        int x=rand()%a.size();
        return a[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */