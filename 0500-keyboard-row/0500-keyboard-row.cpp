class Solution {
public:
    unordered_map< int, unordered_set<char> > m;
    void put( int k,string s){
        for( char ch :s){
            m[k].insert(ch);
        }
    }
    vector<string> findWords(vector<string>& w) {
        
        
        
        string s1="qwertyuiop" , s2="asdfghjkl" , s3="zxcvbnm";
        
        put(1,s1);
        put(2,s2);
        put(3,s3);
        
        vector< string > ans;
        for( string x:w){
            
            for( int i=1;i<=3;i++){
                int fl=1;
                for( char ch :x){
                    ch=ch | 32;
                    if( m[i].find(ch)==m[i].end() ){
                        fl=0;
                        break;
                    }
                }
                if(fl){
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};