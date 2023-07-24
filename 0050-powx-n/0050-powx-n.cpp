class Solution {
public:
    double sol(double x,long long n){
        if(n==0) return 1;
        if(x==1) return x;
        if( n<0) return 1.0/(double)sol(x,-1*n);
        
        if(n%2==1) return x*sol(x*x,(n-1)/2);
        else return sol(x*x,n/2);
    }
    double myPow(double x, int n) {
        return sol(x,n*1LL);
    }
};