class Solution {
    public int[][] onesMinusZeros(int[][] m) {
        int r=m.length, c=m[0].length ;
        
        // ans= 1r +1c -( r-r1)+ (c-1c ) = 2*r1 +2*c2 -(r+c);
        int[] co=new int[r],cz=new int[c];
        
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
}