class Solution {
public:
    int totalHammingDistance(vector<int>& a) {
        int n=a.size(),ans=0;
        vector< int> on( 32, 0);
        
        for( int i=0;i<32;i++){
            for( int x:a){
                on[i]+=x>>i & 1;
            }
            ans+=on[i]*(n-on[i]);
        }
        return ans;
        // for( int x:a){
        //     for( int v=x ,in=0 ; v!=0 ; v=v/2 , in++ ){
        //         if(v%2) on[in]++;
        //     }
        // }
        // int ans=0;
        // for( int i=0;i<32;i++){
        //     ans+=on[i]*(n-on[i]);
        // }
        // return ans;
    }
};
/*
when we are separatly calculating the umber of one for each number for each bits.
class Solution {
public:
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
*/