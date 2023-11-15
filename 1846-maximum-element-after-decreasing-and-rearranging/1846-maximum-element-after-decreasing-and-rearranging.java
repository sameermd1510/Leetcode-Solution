class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] a) {
        
        int n=a.length;
        Arrays.sort(a);
    
        a[0]=1;
        int x=a[0];
        for( int i=1;i<n;i++){
            if(Math.abs(a[i]-a[i-1])>1) {
                a[i]=a[i-1]+1;
            }
            x=Math.max(x,a[i]);
        }
        return x;
        
    }
}