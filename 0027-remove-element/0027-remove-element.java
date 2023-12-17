class Solution {
    public int removeElement(int[] a, int v) {
        
        int k=0;
        for( int i=0;i<a.length;i++){
            if(a[i]!=v){
                a[k++]=a[i];
            }
        }
        return k;
    }
}