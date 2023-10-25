class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 || k==1) return 0;
        int th=pow(2,n-2);
        if(k>th) return 1-kthGrammar(n,k-th);
        else return kthGrammar(n-1,k);
    }
};