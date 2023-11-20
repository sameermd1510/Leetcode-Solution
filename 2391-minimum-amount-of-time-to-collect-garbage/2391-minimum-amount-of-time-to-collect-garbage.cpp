class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        
        int n=g.size()  , ans=0;
        vector< vector< int> > a( n, vector< int> (3,0));
        
        for( int i=0;i<n;i++){
            for( char ch:g[i]){
                if(ch=='M') { a[i][0]+=1;}
                else if(ch=='P') { a[i][1]+=1;}
                else a[i][2]+=1;
            }
            if(i!=0){
                for( int j=0;j<3;j++)  a[i][j]+=a[i-1][j];
            }
            if(i!=0 && i!=n-1) t[i]+=t[i-1];
        }
        /*
        001 001
        010 011
        011 022
        002 024
        */
        for( int j=0;j<3;j++){
            int i=n-1;
            if(a[i][j]==0) continue;
            ans+=a[i][j];
            while( i> 0){
                if( a[i][j] >a[i-1][j]){
                    ans+=t[i-1];
                    break;
                }
                else i--;
            }
        }
        return ans;
    }
};