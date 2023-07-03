class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size() ) return 0; // if not equal length
        
        int i=0,j=0,c=0;
        
        int f[26]={};
        
        for( char ch:s) {  // if frequency of any charater is greater than 1  
            if(++f[ch-'a']>1){ 
                c=1;break;
            }                 
        }
        if(s==g ) return c;  // if string is already destination string then it depend on c, if frequency of any charachter is greater than 1
        
        
        /*
        finding two index where  character mismatched.
        */
        for( ;i<s.size();i++){    
            if(s[i]==g[j]) j++;
            else break; 
        }
        int k=i;
        i++;
        j++;
        for( ;i<g.size();i++){
            if(s[i]==g[j]) j++;
            else break;
        }
        swap(s[k],s[i]);  // swap it.
        return s==g ;
    }
};