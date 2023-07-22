#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define  all(v)            v.begin(), v.end()
#define  sz(a)			   (int)a.size()
#define  debug(x)          cerr << #x << ':' << x << endl;
#define  debuga(a)         cout<<"[ ";rep(i,sz(a)){cout<<a[i]<<" ";}cout<<"]";cout<<endl;
#define  rep(i,n)          for(int i=0;i<n;i++)
#define  reps(i,n)         for(int i=1;i<=n;i++)
#define  srep(t,m)  	   for(auto t:m)
#define  sreps(t,m)	   for(auto t=m.begin();t!=m.end();t++)
#define  pb                push_back
#define  endl              '\n'
#define  fi                first
#define  se                second
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using vii = vector<int>;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using pii =pair< int,int>;
using vpll = vector<pll>;
#define ordered_set  tree< pll ,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> 
class Solution {
public:
    int reversePairs(vector<int>& n) {
        ordered_set a;
        int c=0;
        a.insert({(ll) 2*n[sz(n)-1], (ll)(sz(n)-1)});
        for( int i=sz(n)-2;i>=0;i--){
            c+=a.order_of_key({ n[i], i});
            a.insert({ (ll)2*n[i],i});
        }
        return c;
    }
};