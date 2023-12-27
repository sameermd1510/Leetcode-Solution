class Solution {
public:
    int minCost(string s, vector<int>& a) {
        int ans=0;
        char pre=s[0];
        int smax=a[0],mmax=a[0];
        int c=1;
        
        for( int i=1;i<a.size();i++){
            
            if( pre==s[i] ){
                mmax=max( mmax, a[i]);
                smax +=a[i];
                c++;
            }
            else {
                if( c>1) ans += smax-mmax;
                mmax=a[i];
                smax=a[i];
                pre=s[i];
                c=1;
            }
        }   
        if( c>1) ans += smax-mmax;
        return ans;
    }
    
};