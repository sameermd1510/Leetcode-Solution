class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        
        int n=a.size();
        vector< int > ans(n,0 );
        
        vector< int > st;
        //st.push(0);
        for( int i=n-1 ; i >=0 ;i--){
            
            while(st.size() && a[st.back()] <= a[i] ){
                st.pop_back();
            }
            
            if( st.size()){
                ans[i]=st.back()-i;
            }
            st.push_back(i);
        }
        return ans;
    }
};