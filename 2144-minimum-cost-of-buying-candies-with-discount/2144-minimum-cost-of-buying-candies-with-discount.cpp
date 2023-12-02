class Solution {
public:
    // 2 2 5 6 7 9
    
    int minimumCost(vector<int>& a  ) {
        
        sort(a.begin(),a.end(), greater< int>() );
        int ans=0 ,n=a.size();
        
        for( int i=0;i<n;i++){
            ans+=a[i];
            if(i+1 <n ) {
                ans+=a[i+1];
                i=i+2;
            }
        }
        return ans;
        
    }
};