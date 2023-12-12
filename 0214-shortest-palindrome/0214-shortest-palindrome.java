class Solution {
    
    public static int kmp( String s){
        
        int n=s.length(),i=1,l=0;
        int[] k=new int[n]; // longest proper prefix .
        k[0]=0;
        
        while( i<n){
            if(s.charAt(l)==s.charAt(i)){
                k[i++]=++l;
            }
            else{
                if( l!=0)l=k[l-1];
                else i++;
            }
        }
        return k[n-1];
    }
    public String shortestPalindrome(String s) {
        
        String x=s+"#"+ new StringBuilder(s).reverse().toString();
        return new StringBuilder(s.substring(kmp(x))).reverse().toString()+s;
        
    }
}