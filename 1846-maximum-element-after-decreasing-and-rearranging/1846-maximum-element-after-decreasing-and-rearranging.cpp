class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a ) {
        
        int n=a.size();
        sort(a.begin(),a.end());
        
        a[0]=1;
        int x=a[0];
        for( int i=1;i<n;i++){
            if(abs(a[i]-a[i-1])>1) {
                a[i]=a[i-1]+1;
            }
            x=max(x,a[i]);
        }
        return x;
        
        
    }
};