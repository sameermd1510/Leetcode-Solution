class Solution {
public:
    int maxCoins(vector<int>& a) {
        
        // 1 2 2 4 7 8  
        /*
        8 7 1
        4 2 2
        
        
        1 2 3 4 5 6 7 8 9
        9 8 1
        7 6 2
        5 4 3
        */
        int n=a.size();
        sort(a.begin(),a.end());
        
        int ans=0,k=n/3;
        for( int i=0;i<n/3;i++,k=k+2){
            ans+=a[k];
        }
        return ans;
        
    }
};