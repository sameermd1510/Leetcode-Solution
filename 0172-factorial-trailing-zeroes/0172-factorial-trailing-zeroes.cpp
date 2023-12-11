class Solution {
public:
    int trailingZeroes(int n) {
        
        int ans=0,f=1;
        
        while( 1){
            int x= n/(int)(pow(5,f++));
            if(x!=0) ans+=x;
            else break;
        }
        return ans;
        
    }
};