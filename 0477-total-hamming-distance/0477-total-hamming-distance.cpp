class Solution {
public:
//     2 4 14    
//     2 -0010
//     4 -0100
//     6 -0110
//     14-1110
      
//     z -3114
//     on-1330
//       -3330
    int totalHammingDistance(vector<int>& a) {
        int n=a.size();
        vector< int> on( 32, 0);
        
        for( int x:a){
            for( int v=x ,in=0 ; v!=0 ; v=v/2 , in++ ){
                if(v%2) on[in]++;
            }
        }
        int ans=0;
        for( int i=0;i<32;i++){
            ans+=on[i]*(n-on[i]);
        }
        return ans;
    }
};