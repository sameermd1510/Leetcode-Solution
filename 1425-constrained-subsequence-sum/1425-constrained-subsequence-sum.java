class Solution {
    public int constrainedSubsetSum(int[] a, int k) {
        
        PriorityQueue< int []> pq=new PriorityQueue<>((A,b)->{return b[0]-A[0];});
        
        pq.add(new int[]{a[0],0});
        int ans=a[0];
        for( int i=1;i<a.length;i++){
            while(i-pq.peek()[1]>k){
                pq.poll();
            }
            int cr=Math.max(0, pq.peek()[0])+a[i];
            ans=Math.max(ans,cr);
            pq.add(new int[]{cr,i});
        }
        return ans;
    }
}