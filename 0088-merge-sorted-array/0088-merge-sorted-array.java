class Solution {
    public void merge(int[] a, int m, int[] b, int n) {
        /*
indexing =[  0 1 2 3 4 6]
        a=[  1 2 4 0 0 0]  m+n   ,  m
        b=[ 4 5 6]           n
        // 1 3 6 89 2 4 5
        */
        /*
        for( int i=m ;i<=m+n-1 ; i++) { a[i]=b[i-m]; }  //o(n);
        Arrays.sort(a);  //O( m+n(log(m+n)))   
        
        //   O( n + (m+n)log(m+n) )  ---
        */
        int i=m-1,j=n-1 ,k=m+n-1;
        while( i>=0 || j>=0 ){
            
            //             3 4 5 6
            
            if(i<0){
                a[k]=b[j];
                j--;
                k--;
            }
            else if( j<0){
                a[k]=a[i];
                i--;
                k--;
            }
            else if( a[i]>=b[j] ){
                a[k]=a[i];
                k--;
                i--;
            }
            else{
                a[k]=b[j];
                k--;
                j--;
            }   
        }
    }
}






