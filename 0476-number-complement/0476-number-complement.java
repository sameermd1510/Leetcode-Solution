class Solution {
    public int findComplement(int n) {
        int ans=0,f=0;
        while( n!=0){
            ans=ans+(n%2==0 ?1:0)*(int)Math.pow(2,f++);
            n=n/2;
        }
        return ans;
    }
}