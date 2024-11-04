class Solution {
public:
    string compressedString(string w) {
        
        int c;
        w+="-";
        string ans="" ;      
        for( int i=1; i< w.size() ; i++ ){
            c=1;
            while( w[i]== w[i-1]){
                c++;
                i++;
                if( c>=9){
                    break;
                }
            }
            ans+=to_string(c)+w[i-1];
        }
        return ans;
        
    }
};