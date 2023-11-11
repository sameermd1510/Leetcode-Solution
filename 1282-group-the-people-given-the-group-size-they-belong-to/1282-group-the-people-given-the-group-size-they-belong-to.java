class Solution {
    public List<List<Integer>> groupThePeople(int[] g) {
        
        /*
        [1]
        [0,5]
        [2,3,4]
        */
        List<List<Integer>> ans=new ArrayList<>();
        HashMap< Integer, List<Integer> > m=new HashMap<>();
        
        for( int i=0;i<g.length;i++){
            
            if(!m.containsKey(g[i])){
                m.put(g[i],new ArrayList<>());
            }
            List<Integer> l=m.get(g[i]);
            l.add(i);
                
            if(l.size()==g[i]){
                ans.add(l);
                m.remove(g[i]);
            }
        }
        return ans;
    }
}