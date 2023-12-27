class Solution {
    public int minCost(String s, int[] a) {
        int ans=0;
        char pre=s.charAt(0);
        int smax=a[0],mmax=a[0];
        int c=1;
        
        for( int i=1;i<a.length;i++){
            
            if( pre==s.charAt(i) ){
                mmax=Math.max( mmax, a[i]);
                smax +=a[i];
                c++;
            }
            else {
                if( c>1) ans += smax-mmax;
                mmax=a[i];
                smax=a[i];
                pre=s.charAt(i);
                c=1;
            }
        }   
        if( c>1) ans += smax-mmax;
        return ans;
    }
}