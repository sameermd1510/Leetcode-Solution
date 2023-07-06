class Solution {
    public int maximumProduct(int[] a, int k) {
        
        PriorityQueue<Integer> pq=new PriorityQueue<Integer>();
        long ans=1L,M=1000000007L;

        for( int x:a) pq.add(x);
        
        while(k-- >0){
            pq.add(pq.poll()+1);
        }
        while(!pq.isEmpty()){
            ans=(ans*pq.poll())%M;
        }
        return (int)ans;
    }
}