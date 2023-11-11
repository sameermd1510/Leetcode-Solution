class Solution {
public:
    int ans=0;
    int dp[502][503];
    int sol( int i, vector< int>& ss, int t){
        if(i>=ss.size() ) return 0;
        
        if(dp[i][t]!=-1) return dp[i][t];
        
        return dp[i][t]=max( ss[i]*t+sol(i+1,ss,t+1) , sol( i+1, ss,t));
        
    }
    /*
  0  0   0   0    0   0
    -9 -8  -1    0   5
        -9 -9   -1   10
           -9     
    */
    int maxSatisfaction(vector<int>& ss) {
        
        // -9 -8 -1 0 5 
        memset(dp,-1,sizeof(dp));
        sort(ss.begin(),ss.end());
        return sol(0,ss,1);
    }
};


// class Solution {
// public:
//     int ans=0;
//     //int dp[502][502];
//     map< pair< int,int> , int> dp;
//     int sol( int i, vector< int>& ss, int count, int t){
//         if(i>=ss.size() ){
//             //ans=max(ans,count);
//             return 0;
//         }
        
//         //if(dp[i][t]!=-10001) return dp[i][t];
//         //return dp[i][t]=max( sol(i+1,ss,count+ss[i]*t ,t+1) , sol( i+1, ss,count , t));
//         if(dp.contains({i,t})>0) return dp[{i,t}];
//         return dp[{i,t}]=max( sol(i+1,ss,count+ss[i]*t ,t+1) , sol( i+1, ss,count , t));
        
//     }
//     /*
//   0  0   0   0    0   0
//     -9 -8  -1    0   5
//         -9 -9   -1   10
//            -9     
//     */
//     int maxSatisfaction(vector<int>& ss) {
        
//         // -9 -8 -1 0 5 
//         // for( int i=0;i<502;i++){
//         //     for( int j=0;j<502;j++)INT_MIN+500000;
//         // }
//        // memset(dp,-10001,sizeof(dp));
//         sort(ss.begin(),ss.end());
//         int count=0;
//         sol(0,ss,count,1);
        
//         // for( int i=0;i<ss.size();i++){
//         //     for( int j=0;j<ss.size();i++){
//         //         cout<<dp[i][j]<<" ";
//         //     }
//         //     cout<<"\n";
//         // }
//         //cout<<"\n\n";
//         for( auto t:dp){
//             cout<<"{"<<t.first.first<<","<<t.first.second<<"} "<<t.second<<"\n";
//             ans=max(ans, t.second);
//         }
//         return ans;
//     }
// };
