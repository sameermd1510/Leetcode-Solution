class Solution {
public:
    long long countFairPairs(vector<int>& a, int l, int u) {
        
        long long ans=0;
        
        sort( a.begin() , a.end());
        
        for( int i=0 ; i<a.size()-1 ; i++ ) {    
            long long si= upper_bound( a.begin()+i+1 , a.end() , u-a[i])
                - lower_bound( a.begin()+i+1, a.end() , l-a[i]) ;
            
            ans+=si;
            
        }
        return ans;
    }
};