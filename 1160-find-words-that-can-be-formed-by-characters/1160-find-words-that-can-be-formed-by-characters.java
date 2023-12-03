class Solution {
    public int countCharacters(String[] a, String s) {
        int ans=0;
        
        int f[]=new int[26];
        
        for( char ch:s.toCharArray()) f[ch-'a']++;
        
        for( String x:a){
            
            int c[]=new int[26];
            for( char ch:x.toCharArray()){
                c[ch-'a']++;
            }
            int fl=1;
            for( int i=0;i<26;i++){
                if( c[i] > f[i]){
                    fl=0;
                    break;
                }
            }
            if(fl==1) ans+=x.length();
        }
        return ans;
        
    }
}