class Solution {
public:
    int minOperations(vector<int>& a) {
        int in=0,ans=0;
        
        for( int i=0;i<a.size();i++){
            if(a[i]>in){
                in=a[i]+1;
            }
            else{
                ans+=abs(a[i]-in);
                in=in+1;
            }
        }
        return ans;
    }
};