class Solution {
public:
    int maximumProduct(vector<int>& a, int k) {
        
        priority_queue< int, vector< int> , greater< int> > pq;
        long long ans=1,M=1e9+7;
        for( int x:a) pq.push(x);
        
        while( k--){
            int x=pq.top();pq.pop();
            pq.push(x+1);
        }
        
        while(!pq.empty()){
            ans=( ans*pq.top())%M;
            pq.pop();
        }
        return ans; 
        
    }
};