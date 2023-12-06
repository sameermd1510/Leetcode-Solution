class Solution {
public:
    vector<int> constructRectangle(int A) {
        
        for( int i=sqrt(A) ;i>=1;i--){
            if(A%i==0) return {A/i,i};
        }
        return {0,0};
    }
};