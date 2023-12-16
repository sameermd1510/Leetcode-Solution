class Solution {
public:
    
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        
        string s="011",st="";
        
        if(n==2) return s[k-1];
        for( int i=3;i<=n;i++){
            st=s+"1";
            
            for( int i=s.size()-1;i>=0;i--) st+=(s[i]=='1') ?'0':'1';
            s=st;
            // cout<<st<<"\n";
        }
        return st[k-1];
    }
};