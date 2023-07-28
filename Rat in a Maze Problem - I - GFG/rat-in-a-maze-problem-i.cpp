//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector< string> ANS;
    int N;
    
    bool check( int x,int y){
        return min(x,y)>=0 && x<N && y<N;
    }
    void sol(vector<vector<int>> &m,int x, int y, vector<vector<bool>>& vis ,string s){
        
        if(x==N-1 && y==N-1) {
            ANS.push_back(s);
            return ;
        }
        if(!check(x,y) ) return ;
        
        if(m[x][y]==0) return ;
        
        vis[x][y]=1;
        if(check( x,y+1) && m[x][y+1]!=0 && !vis[x][y+1]){
            vis[x][y+1]=1;
            sol(m,x,y+1,vis,s+"R");
            vis[x][y+1]=0;
        }
        if(check( x,y-1) && m[x][y-1]!=0 && !vis[x][y-1]){
            vis[x][y-1]=1;
            sol(m,x,y-1,vis,s+"L");
            vis[x][y-1]=0;
        }
        if(check( x+1,y) && m[x+1][y]!=0 && !vis[x+1][y]){
            vis[x+1][y]=1;
            sol(m,x+1,y,vis,s+"D");
            vis[x+1][y]=0;
        }
        if(check( x-1,y) && m[x-1][y]!=0 && !vis[x-1][y]){
            vis[x-1][y]=1;
            sol(m,x-1,y,vis,s+"U");
            vis[x-1][y]=0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        N=n;
        if(m[0][0]==0 || m[n-1][n-1]==0) return {"-1"};
        vector< vector< bool> > vis( n, vector< bool> (n,false));
        sol(m,0,0,vis,"");
        return ANS;
        /*queue< pair< pair< int, int> , string >> q;
        vector< vector< bool> > vis( n, vector< bool> (n,false));
        
        q.push({{0,0},""});
        vis[0][0]=1;
        
        while(!q.empty()){
            auto t=q.front();q.pop();
            
            int x=t.first.first;
            int y=t.first.second;
            string ans=t.second;
            
            if(x==n-1 && y==n-1){
                ANS.push_back(ans);
                continue;
            }
            
            if(check( x,y+1) && m[x][y+1]!=0 && !vis[x][y+1]){
                q.push({{x,y+1},ans+"R"});
                vis[x][y+1]=1;
            }
            if(check( x,y-1) && m[x][y-1]!=0 && !vis[x][y-1]){
                q.push({{x,y-1},ans+"L"});
                vis[x][y-1]=1;
            }
            if(check( x+1,y) && m[x+1][y]!=0 && !vis[x+1][y]){
                q.push({{x+1,y},ans+"D"});
                vis[x+1][y]=1;
            }
            if(check( x,y+1) && m[x][y+1]!=0 && !vis[x][y+1]){
                q.push({{x,y+1},ans+"R"});
                vis[x][y+1]=1;
            }
        }*/
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends