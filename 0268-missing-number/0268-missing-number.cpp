class Solution {
public:
    int missingNumber(vector<int>& a) {
        
        int sum=a.size();
        
        sum= (sum)*( sum+1)/2;
        
        for( int x:a) sum-=x;
        
        return sum;
        
    }
};