class Solution {
    public String destCity(List<List<String>> p) {
        
        HashSet<String> m=new HashSet<>();
        
        for( int i=0;i<p.size();i++){
            m.add(p.get(i).get(0));
        }
        
        for( int i=0;i<p.size();i++){
            if( !m.contains( p.get(i).get(1) ) ) return p.get(i).get(1);
        }
        
        return "";
        
    }
}