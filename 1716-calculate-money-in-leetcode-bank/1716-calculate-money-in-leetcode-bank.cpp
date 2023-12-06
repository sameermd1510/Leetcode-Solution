class Solution {
public:
    int dp[7]={ 1,2,3,4,5,6,7};
    int totalMoney(int n) {
        
        int ans=0;
        for( int i=0;i<n;i++){
            ans+=dp[i%7];
            dp[i%7]++;
        }
        return ans;
    }
};