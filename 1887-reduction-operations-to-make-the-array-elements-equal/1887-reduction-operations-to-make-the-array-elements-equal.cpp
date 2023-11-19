class Solution {
public:
    int reductionOperations(vector<int>& a) {
        
        map< int, int,greater<int>> m;
        for( int x:a) m[x]++;
    
        int prev=0, ans=0 , n=m.size() ;
        
        for( auto& t:m){
            if(n==1) break;
            ans=ans+ (t.second+prev);
            prev+=t.second;
            n--;
        }
        return ans;
    }
};
/*
input = [1,2,2,2,3,3,3,4]
1
1 1+3
5 4+3
*/