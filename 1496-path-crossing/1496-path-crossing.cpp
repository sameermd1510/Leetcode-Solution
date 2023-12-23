class Solution {
public:
    bool isPathCrossing(string p) {
        
        unordered_map< char, pair< int, int> > m;
        
        m['N']={0,1};
        m['S']={0,-1};
        m['E']={1,0};
        m['W']={-1,0};
        unordered_set< string> s;
        
        int px=0,py=0;
        s.insert("0-0");
        for( char ch:p){
            
            auto t=m[ch];
            int x=px+t.first , y=py+t.second;
            
            string str=to_string(x)+"-"+to_string(y);
            if( s.find(str)==s.end()){ 
                s.insert(str);
                px=x;
                py=y;
            }
            else 
                return true;
        }
        return 0;
    }
};