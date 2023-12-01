#define sz(a)  (int)a.size()
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int n1=w1.size() , n2=w2.size() , r1=0 ,c1=0 , r2=0 , c2=0;
        
        while( r1<n1 && r2<n2 ){
            
            if( w1[r1][c1]!= w2[r2][c2]) return false;
            
            c1++;
            c2++;
            if(c1 >= sz(w1[r1]) ) r1++ , c1=0;
            if(c2 >= sz(w2[r2])) r2++ , c2=0;
            
        }
        return ( r1==n1 && r2==n2 ) ;
    }
};