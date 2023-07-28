//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string shortestPath (string S){
        int x=0,y=0;
        for( char ch:S){
            if(ch=='N') x++;
            else if(ch=='S') x--;
            else if(ch=='E') y++;
            else y--;
        }
        string ans="";
        
        for( int i=0;i<abs(y);i++){
            if(y>0)ans+="E";
            else ans+="W";
        }
        for( int i=0;i<abs(x);i++){
            if(y>0){
                if(x>0) ans+="N";
                else ans+="S";
            } 
            else{
                if(x>0) ans="N"+ans;
                else ans="S"+ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.shortestPath (s) << endl;
    }
}

// } Driver Code Ends