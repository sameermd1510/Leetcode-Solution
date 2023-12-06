class Solution {
    /*
    3 6 7 11
    */
    public static long count( int[] p , long v){
        
        long cnt=0;
        for( int x:p){
            if( x>=v) cnt+=x/v + ( x%v >0 ? 1:0);
            else cnt++;
        }
        return cnt;
    }
    public int minEatingSpeed(int[] p, int h) {
        long l=1,u=-1;
        
        for( int x:p)  u=Math.max(u,x);
        
        while( l<=u){
            long mid=l+(u-l)/2;
            
            long val=count(p,mid);
            // System.out.println(val);
            if( val >h){
                l=mid+1;
            }
            else
                u=mid-1;
        }
        return (int)l;
        
    }
}