#define  all(v)            v.begin(), v.end()
#define  sz(a)			   (int)a.size()
#define  debug(x)          cerr << #x << ':' << x << endl;
#define  debuga(a)         cout<<"[ ";rep(i,sz(a)){cout<<a[i]<<" ";}cout<<"]";cout<<endl;
#define  rep(i,n)          for(int i=0;i<n;i++)
#define  reps(i,n)         for(int i=1;i<=n;i++)
#define  pb                push_back
#define  endl              '\n'
#define  fi                first
#define  se                second
using ll = long long;
using vii = vector<int>;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
class Solution {
public:
    
    vector<string> ans;
    vector<string> letterCombinations(string d)
    {
        unordered_map< int,string> m;
        
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";

        vector<int> di(4,0);
        rep(i, sz(d)) di[i]=(d[i]-'0');

        string s="";
        int f=0;
        rep(i, sz( m[di[0]]))
        {
            f=0;
            s=s+m[di[0]][i];
            rep(j,sz(m[di[1]]))
            {
                f=1;
                s=s+ m[di[1]][j] ;
                rep(k,sz( m[ di[2]]))
                {
                    f=2;
                    s=s+m[di[2]][k];
                    rep( aa,sz(m[di[3]] ))
                    {
                        f=3;
                        s=s+m[di[3]][aa];
                        if(f==3) ans.push_back(s);
                        s.pop_back();
                    }
                    if(f==2) ans.push_back(s);
                    s.pop_back();
                }
                
                if(f==1) ans.push_back(s);
                    s.pop_back();
            }
            if(f==0){ ans.pb(s);}
            s.pop_back();
        }
        return ans;
    }
};