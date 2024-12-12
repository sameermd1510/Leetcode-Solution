class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        
        long long ans=0;
        priority_queue< int> pq;
        
        for( int x:g) {
            ans += x*1LL;
            pq.push(x);
        }
        
        while( k--){
            int x= pq.top();
            pq.pop();
            ans-= x*1LL;
            
            ans += ( long long) ( sqrt(x));
            
            pq.push(sqrt(x));
        }
        
        return ans;
        
    }
};