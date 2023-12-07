class Solution {
    public String largestOddNumber(String s) {
        
        int st=-1 , en=-1;
        for( int i=0;i<s.length();i++){
            if( (s.charAt(i)-'0' )%2==1 ){
                if(st==-1) st=i;
                else en=i;
            }
        }
        
        if( st==-1) return "";
        else if(st==s.length()-1 || en==s.length()-1) return s;
        
        else if( en==-1) return s.substring(0,st+1);
        
        return s.substring(0,en+1);
//         String l=s.substring(0,st+1) , m=s.substring(st,en+1);
        
//         return ( Integer.parseInt(l) < Integer.parseInt(m) ) ?  m :l;
    }
}