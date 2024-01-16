class AllOne {
public:
    
    unordered_map< string , int> m;
    set< pair<int,string> > s;
    
    AllOne() {
        
    }
    
    void inc(string key) {
        
        if(m.find(key)!=m.end()){
            s.erase({m[key], key});            
        }
        m[key]++;
        s.insert({m[key] , key});
        
    }
    
    void dec(string key) {
        
        s.erase({m[key], key});            
        if(m[key]==1) m.erase(key);
        else {
            m[key]--;
            s.insert({m[key] , key});
        }
    }
    
    string getMaxKey() {
        return(s.size())? s.rbegin()->second :"";
    }
    
    string getMinKey() {
        return(s.size())? s.begin()->second :"";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */