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
        
        if(m.find(key)!=m.end()){
            s.erase({m[key], key});            
        }
        
        if(m[key]==1) m.erase(key);
        else {
            m[key]--;
            s.insert({m[key] , key});
        }
    }
    
    string getMaxKey() {
        
        // for( auto t:s){
        //     cout<<t.second<<" "<<t.first<<" ";
        // }
        // cout<<"\n";
        if(s.size())
        return s.rbegin()->second;
        else return "";
    }
    
    string getMinKey() {
        
        // for( auto t:s){
        //     cout<<t.second<<" "<<t.first<<" ";
        // }
        // cout<<"\n";
        if(s.size()) return s.begin()->second;
        else return "";
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