class Solution {
    public boolean makeEqual(String[] w) {
        
        if( w.length==1) return true;
        int[] m=new int[26];
        Arrays.fill(m,0);
        
        
        for( String s:w){
            for( char ch:s.toCharArray()) { m[ch-'a']++; }
        }
        for( int i=0;i<26;i++){ 
            if(m[i]==0) continue;
          if( m[i] % w.length !=0) return false;
        }
        return true;
        
    }
}