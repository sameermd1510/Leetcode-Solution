class Solution {
public:
    vector< int > bl , br ;

    int getSum( vector< int> &a,int index) {
        int sum=0;
        while( index >0){
            sum+=a[index];
            index -= ( index & -index) ;
        }
        return sum;
    }

    void updateBIT( vector< int> &a , int index , int val){
        while( index <a.size()){
            a[index]+=val;
            index += ( index & -index);
        }
    }
    
    int numTeams(vector<int>& r) {
        
        int n=r.size();
        
        // Compressing Co-ordinates So that size of BIT should be Equal to no of Element
        vector< int> s(r) ;
        sort( s.begin() , s.end() );
        for( int &x :r ) {
            x= lower_bound( s.begin() , s.end() , x) -s.begin() +1;
        }
        //
        
        bl.resize( n+1 ,0);
        br.resize( n+1 ,0);
        
        for( int x: r) {
            updateBIT( br , x, 1);
        }

        
        int ans=0 ;
        for( int x :r) {
            
            updateBIT( br , x, -1) ;
            
            int sl = getSum ( bl , x-1);
            int sr = getSum ( br , x-1) ;
            
            int ll = getSum ( bl , n)- getSum( bl ,x);
            int lr = getSum( br , n)- getSum( br , x) ;
            
            ans += ( sl * lr);
            ans += ( ll * sr);
            
            updateBIT( bl ,x,1);
        }
        return ans;
    }
};