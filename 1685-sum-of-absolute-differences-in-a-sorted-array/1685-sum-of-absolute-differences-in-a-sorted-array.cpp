class Solution {
public:
    /*
        initial Array = [2 3 5 ]
        PreFix Sum =[ 2 5 10 ]
        a[i] = sum of abs diff of Left  + summ of abs diff of Right.
        sum for right part= (pre[n-1]-pre[i])-a[i]*(n-i-1);
        sum for left part = (pre[i])-a[i]*(i+1);
    */
    vector<int> getSumAbsoluteDifferences(vector<int>& a) {
        
        int n=a.size();
        vector< int > pre(a);
        
        for( int i=1;i<n;i++) pre[i]+=pre[i-1];
        for( int i=0;i<n;i++){
            a[i]= abs(pre[i] -a[i]*(i+1) ) + abs( (pre[n-1]-pre[i]) -a[i]*(n-1-i));
        }
        return a;    
    }
};