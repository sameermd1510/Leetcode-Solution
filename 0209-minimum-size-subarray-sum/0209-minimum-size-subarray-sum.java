class Solution {
    public int minSubArrayLen(int t, int[] a) {
        int ans=Integer.MAX_VALUE,i=0,j=0,sum=0;
        while(i<a.length){
            sum+=a[i];
            while(sum>=t){
                ans=Math.min(ans, i-j+1);
                sum-=a[j++];
            }
            i++;
        }
        return ans==Integer.MAX_VALUE ?0:ans;
        
    }
}