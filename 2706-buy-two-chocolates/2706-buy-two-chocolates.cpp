class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        int fs=INT_MAX , ss=INT_MAX;
        int a=-1,b=-1;
        for( int i=0;i<p.size() ;i++){
            if(fs >p[i]){
                if(fs!=INT_MAX){
                    ss=fs;
                    b=a;
                    fs=p[i];
                    a=i;
                }
                else{
                    fs=p[i];
                    a=i;
                }
            }
            else{
                if( ss > p[i]){
                    ss=p[i];
                    b=i;
                }
            }
        }
        return ( m-fs-ss) >=0 ? (m-fs-ss) : m;
    }
};