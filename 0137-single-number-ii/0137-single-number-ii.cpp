class Solution {
public:
    int singleNumber(vector<int>& a) {
        
        int ans=0;
        for( int i=0;i<32;i++){
            int sum=0;
            for( int x:a){
                sum+=(x>>i)&1;
            }
            sum%=3;
            ans |=sum<<i;
        }
        return ans;
    }
};