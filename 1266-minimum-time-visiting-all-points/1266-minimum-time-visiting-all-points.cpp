class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& a) {
        
        int ans=0;
        for( int i=1;i<a.size();i++){
            int x=abs(a[i][0]-a[i-1][0] );
            int y=abs( a[i][1]-a[i-1][1] );
            
            ans+=min(x,y);
            ans+=max(x,y)-min(x,y);
        }
        return ans;
    }
};