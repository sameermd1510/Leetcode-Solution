class Solution {
public:
    
    vector< int> kmp( string s){
        
        int n=s.size();
        vector< int> k(n,0); // longest proper prefix .
        int i=1,l=0;
        
        while( i<n){
            if(s[l]==s[i]){
                l++;
                k[i]=l;
                i++;
            }
            else{
                if( l!=0){
                    l=k[l-1];
                }
                else{
                    i++;
                }
            }
        }
        return k;
        
    }
    string shortestPalindrome(string s) {
        
        string x=s;
        reverse(x.begin(),x.end());
        vector< int> a=kmp(s+"#"+x);
        
        // ( ( substr(l).reverse+longest pallindrome prefix i.e from start(i=0))
        x=s.substr(a.back());
        reverse(x.begin(),x.end());
        return x+s;
    }
};