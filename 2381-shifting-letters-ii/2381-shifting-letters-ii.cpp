class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& a) {
        
        vector<int> v(s.size(), 0);
        
        for( vector<int> x:a){
            int st=x[0]  , en=x[1]  , d=(x[2])?1:-1;
            v[st]+=d;
            if(en+1<s.size()) v[en+1]-=d;
        }
        
        for( int i=1;i<v.size();i++) v[i]+=v[i-1];
        int i=0;
        for( char &ch:s){
            
            int increaseBy=(ch-'a'+v[i++])%26;
			increaseBy=(increaseBy+26)%26;
			ch='a'+increaseBy;
        }
        
        return s;
        
         
    }
};

/*


a   b  c



-1     1
    1    -1
1         -1
----------------
0   1   2 0
-1 -1
    1  1
1   1  1
0   1  2
*/