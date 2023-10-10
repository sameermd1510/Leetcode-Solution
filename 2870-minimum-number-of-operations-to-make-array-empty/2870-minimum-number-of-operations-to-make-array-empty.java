class Solution {
    public int minOperations(int[] a) {
        HashMap< Integer, Integer> m=new HashMap<>();
        for(int x:a){
            if(m.containsKey(x)){
                m.put(x,m.get(x)+1);
            }
            else m.put(x,1);
        }
        // 3 3 3 2
        int ans=0;
        for( Map.Entry<Integer,Integer> x:m.entrySet()){
            
            int k=x.getKey();
            int v=x.getValue();
            
            if(v==1) return -1;
            ans+=(v+2)/3;
        }
        return ans;
        
    }
}