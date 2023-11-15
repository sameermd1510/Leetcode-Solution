class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a ) {
        
        int n=a.size();
        sort(a.begin(),a.end());
        
        a[0]=1;
        for( int i=1;i<n;i++){
            if(abs(a[i]-a[i-1])<=1) continue;
            else{
                a[i]=a[i-1]+1;
            }
        }
        // for( int x:a) cout<<x<<" ";
        // cout<<"\n";
        
        return *max_element(a.begin(),a.end());
        
        
    }
};