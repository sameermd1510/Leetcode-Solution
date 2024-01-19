#define ll long long 
class Solution {
public:
    
    ll check( vector<int>& t, ll v , int totalTrips ){
        
        ll ct=0;
        
        for( int x: t){
            ct+= ( v/x);
        }
        return ct-totalTrips;
    }
    long long minimumTime(vector<int>& t, int totalTrips ) {
        
        ll mn=LLONG_MAX;
        
        for( int x: t) { 
            mn=min( mn, x*1LL);
        }
        
        ll ans=mn*(1LL *totalTrips);
        ll lb=0, ub=ans;
        
        while( lb < ub){
            ll m= ( lb+ ( ub-lb)/2);
            
            
            if( check( t,m,totalTrips) >=0){
                ub=m;
            }
            else lb=m+1;
        }
        
        return lb;
    }
};