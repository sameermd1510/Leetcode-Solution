class Solution {
public:
    int minDifference(vector<int>& a) {
        
        // 2 3 4 5 6
        //
        int ans , n=a.size();
        
        if ( n <5) return 0;
        sort( a.begin() , a.end());
        
        ans= a[n-4] -a[0];
        for( int i=0;i<4;i++) {
            ans= min ( ans , abs( a[n-4 +i]-a[i]));
        }
        return ans;
    }
};