class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        
        int j=0,ans=1,ans1=1,f=k;
        
        for( int i=0;i<s.size();i++){
            if(s[i]=='F') k--;
            
            while( j<s.size() && k<0){
                if(s[j++]=='F') k++;
                
            }
            ans=max( ans, i-j+1);
        }
        j=0;
        for( int i=0;i<s.size();i++){
            if(s[i]=='T') f--;
            
            while( j<s.size() && f<0){
                if(s[j++]=='T') f++;
                
            }
            ans1=max( ans1, i-j+1);
        }
        
        return max( ans,ans1 );
        
    }
};