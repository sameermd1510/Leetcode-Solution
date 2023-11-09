class Solution {
public:
    int m=1e9+7;
    int countHomogenous(string s) {
        long long ans=0;
        
        long long f=1;
        
        for( int i=1;i<s.size();i++){
            
            if( s[i]==s[i-1]) f++;
            else{
                ans += (( f*(f+1))%m/2)%m;
                f=1;
            }
        }
        
        ans += ((f*(f+1))%m/2);
        return ans%m;
    }
};