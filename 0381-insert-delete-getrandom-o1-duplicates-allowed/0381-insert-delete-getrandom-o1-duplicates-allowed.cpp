class RandomizedCollection {
public:
    
    unordered_map< int, unordered_set< int> > m;
    vector< int> a;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        a.push_back(val);
        m[val].insert(a.size()-1);
        
        return m[val].size()==1;
    }
    
    bool remove(int val) {
        auto t=m.find(val);
        if( t!=m.end()){
            
            auto in=*t->second.begin();
            t->second.erase(t->second.begin());
            
            a[in]=a.back();
            m[a.back()].insert(in);
            m[a.back()].erase(a.size()-1);
           
            a.pop_back();
            
            if( t->second.size()==0) m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */