class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n=a.size();
        int ans=0,k=n/3;
        
        sort(a.begin(),a.end());
        for( int i=0;i<n/3;i++,k=k+2){
            ans+=a[k];
        }
        return ans;
        
    }
};