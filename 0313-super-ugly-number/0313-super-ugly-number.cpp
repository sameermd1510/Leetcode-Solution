class Solution {
public:
    /*
    2 7 13 19
    1 2 4
        7 14 13 19 26 38  
        
    */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int N=primes.size();
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        vector<long long> dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int j=i-1;
            for(int k=0;k<N;k++){
                pq.push(dp[j]*primes[k]);
            }
            while(pq.top()<=dp[j]){
                pq.pop();
            }
            dp[i]=pq.top();
            pq.pop();
        }
        return dp[n];
    }
};