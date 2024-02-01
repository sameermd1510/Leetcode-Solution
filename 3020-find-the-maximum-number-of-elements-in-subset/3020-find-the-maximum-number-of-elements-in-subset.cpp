class Solution {
public:
    int maximumLength(vector<int>& a) {
        sort(a.begin() ,a.end());
        
        unordered_map< long long, int > m;
        for( int i:a) m[i]++;
        int ans=( m[1] %2==0 ) ? ( m[1]-1) : m[1];
        int c=0;
        a.assign( a.begin() ,unique(a.begin() , a.end()) );
        
        
        // 1 16 49 121 
        //   
        for( int i=0;i<a.size() ;i++){
            
            c=0;
            if( a[i]==1) continue;
            
            int fl=0;
            long long v=a[i];
            int j=i+1;
            while( m.find( v)!=m.end() ){
                if( m[v] >1) c+=2;
                else if( m[v]==1 ){
                    c+=1;
                    fl=1;
                    break;
                }
                v=v*v;
            }
            if( fl ==1 || c >=2) {
                if( c%2==0) c--;
                ans=max( ans , c);
            }
            
        }
        return ans;
        
    }
};