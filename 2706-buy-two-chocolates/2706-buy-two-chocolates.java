class Solution {
    public int buyChoco(int[] p, int m) {
        
        int fs=Integer.MAX_VALUE , ss=Integer.MAX_VALUE;
        int a=-1,b=-1;
        
        for( int i=0;i<p.length ;i++){
            if(fs >p[i]){
                
                if(fs!=Integer.MAX_VALUE){
                    ss=fs;
                    b=a;
                    fs=p[i];
                    a=i;
                }
                else{
                    fs=p[i];
                    a=i;
                }
            }
            else{
                if( ss > p[i]){
                    ss=p[i];
                    b=i;
                }
            }
        }
        // System.out.println(fs+" "+ss);
        
        return ( m-fs-ss) >=0 ? (m-fs-ss) : m;
    }
}