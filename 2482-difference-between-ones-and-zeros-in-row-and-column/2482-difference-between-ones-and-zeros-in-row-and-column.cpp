class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& m) {
        int r=m.size(), c=m[0].size() ;
        
        // x= 1r +1c -( r-r1)+ (c-1c ) = 2*r1 +2*c2 -(r+c);
        
        vector< int> co(r,0),cz(c,0);
        
        for( int i=0;i<r;i++){
            for( int j=0;j<c;j++){
                if(m[i][j]==1){
                    co[i]++;
                    cz[j]++;
                }
            }
        }
        
        for( int i=0;i<r;i++){
            for( int j=0;j<c;j++){
                
                m[i][j]= 2*co[i] +2*cz[j]-(r+c);
            }
        }
        return m;
    }
};