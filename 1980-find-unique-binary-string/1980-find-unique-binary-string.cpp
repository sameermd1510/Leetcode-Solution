class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) {
        
        int n=a.size(),i=0;
        
        unordered_set< unsigned long> s;
        for( i=0;i<n;i++){
            bitset<16> bt(a[i]);
            s.insert( bt.to_ulong() );
        }
        for(unsigned long i=0;i<=(unsigned long)(pow(2,n)-1);i++){
            if(s.find(i)==s.end()){
                string ans="";
                
                while( i!=0){
                    ans=to_string(i%2)+ans;
                    i=i/2;
                }
                while(ans.size()!=n) ans="0"+ans;
                return ans;
            }
        }
        
        return "";
    }
};