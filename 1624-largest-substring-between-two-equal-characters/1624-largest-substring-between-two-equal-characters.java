class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        
        HashMap< Character, Integer> m=new HashMap<>();
        int ans=0 , n=s.length();
        
        for( int i=0;i<n;i++){
            
            char l=s.charAt(i);
            char r=s.charAt(n-i-1);
        
            if( m.containsKey(l)){
                
                ans=Math.max( ans , Math.abs(m.get(l)-i));
                
                m.put(l, Math.min(i, m.get(l)));
            }
            else{
                m.put(l,i);
            }
            
            if(m.containsKey(r)){
                ans=Math.max( ans , Math.abs(m.get(r)-(n-i-1)));
                
                 m.put(r, Math.max(n-i-1, m.get(r)));
            }
            else{
                m.put(r,(n-i-1));
            }
        }
        return ans-1;
        
    }
}