class Solution {
    public int minSizeSubarray(int[] a, int t) {
        
        long sum=0L , s=0L;
        int n=a.length;
        
        for( int x:a) sum+=x;
        
        int k=(int)(t/sum), ans=n;
        t%=sum;
                
        if(t==0) return k*n;
        
        HashMap< Long, Integer> m=new HashMap<>();
        m.put(0L ,-1);
        for( int i=0;i<2*n;i++){
            s+=a[i%n];
            if(m.containsKey(s-t)) ans=Math.min(ans,i- m.get(s-t));
            
            m.put(s,i);
        }
        return ans<n ? ans+k*n:-1;
    }
}