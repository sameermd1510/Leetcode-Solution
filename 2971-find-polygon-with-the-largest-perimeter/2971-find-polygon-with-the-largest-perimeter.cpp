#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& a) {
        
        sort( a.begin() , a.end());
        ll ans=a[0],l=1;
        
        vector< ll> sm(a.size());
        sm[0]=a[0]*1LL;
        for( int i=1;i<a.size();i++) sm[i]+=sm[i-1]+a[i];
        
        // 1 1 2 3 5 12 50
        // 1 2 4 7 12 54 104
        // 
        int i=a.size()-1;
        
        while( i>=2){
            if( i>=1 && sm[i-1] > a[i]){
                return sm[i];
            }
            i--;
        }
        return -1;
        
    }
};