class Solution {
    public int totalHammingDistance(int[] a) {
        int n=a.length,ans=0;
        int on[]=new int[32];
        
        for( int i=0;i<32;i++){
            on[i]=0;
            for( int x:a){
                on[i]+=(x>>i) & 1;
            }
            ans+=on[i]*(n-on[i]);
        }
        return ans;
        
    }
}