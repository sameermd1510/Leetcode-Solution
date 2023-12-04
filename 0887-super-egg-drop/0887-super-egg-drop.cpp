vector< vector< int> > dp( 101 , vector< int>( 10001,-1));
// vector< vector< int> > dp( 10001 , vector< int>( 101,-1)); // for solve.
class Solution {
public:

    // k - eggs and n - floors
    int superEggDrop(int k, int n) {
        
        if(n==1 || n==0) return n;
        if(k==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];
        
        int ans=INT_MAX , l=1 ,r=n;
        
        while( l<=r){
            int m= l+(r-l)/2;
            
            int egbreak=superEggDrop( k-1 , m-1);
            int egnotbreak=superEggDrop(k, n-m);
            
            if( egbreak < egnotbreak ){
                l=m+1;
            }
            else
                r=m-1;
            ans=min( ans , 1+ max(egbreak, egnotbreak ));
        }
        return dp[k][n]=ans;
        
        // time imit Exceed.
//         if( dp[k][n]!=-1) return dp[k][n];
        
//         // if i have o or 1 floor theni require o or 1  trials only.
//         if(n==0 || n==1) return n;
        
//         // if 1 egg then i have to drop from bottom and check on which foor it breaks.
//         if( k==1) return n;
        
//         int ans=INT_MAX;
//         for( int fl=1 ; fl<=n;fl++){
            
//             //   res= 1+max ( if egg break then we are left with k-1 egss and we have to check for down flors (fl-1 ) only ,
//             //       if eggs doesnt Break then we have k eggs remains and we will  have to check remainng floor (n-fl ) );
//             int res=1+max( superEggDrop( k-1, fl-1)  , superEggDrop( k , n-fl ));
            
//             if( res < ans) ans=res;
            
//         }
//         dp[k][n]=ans;
//         return ans;
    }
    int solve(int floor, int egg) {
        if(floor == 0 || floor == 1) return floor;
        if(egg == 1) return floor;
        if(dp[floor][egg] != -1) return dp[floor][egg];
        int mi = INT_MAX, l = 1, r = floor;
        while(l < r){
            int mid = l + (r - l) / 2;
            
            int left = solve(mid - 1, egg - 1); //egg broken check for down floors of mid.
            
            int right = solve(floor - mid, egg); // not broken check for up floors of mid.
            
            if(left >= right) {   //left >= right so we will go downward
                r = mid;
            } else { //since right is more than left and we need more in worst case 
                l = mid + 1;  // so l=mid+1 to gain more  for worst case : upward
            }
            mi = min(mi, 1+max(left, right)); //store minimum attempts of (max of both left, right )
        }
        return dp[floor][egg] = mi;
    }

};