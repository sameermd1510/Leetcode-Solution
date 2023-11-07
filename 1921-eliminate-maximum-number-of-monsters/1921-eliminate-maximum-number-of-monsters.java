class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        
        PriorityQueue< Double> pq=new PriorityQueue<>();
        
        for( int i=0;i<dist.length;i++){
            pq.add( (double)dist[i]/(speed[i]*1.0));
        }
        
        int c=0,min=0;
        
        while(!pq.isEmpty()){
            double x=pq.poll();
            
            if( (x-min*1.0)*10 >0 ){
                c++;
                min++;
            }
            else break;
        }
        return c;
    }
}