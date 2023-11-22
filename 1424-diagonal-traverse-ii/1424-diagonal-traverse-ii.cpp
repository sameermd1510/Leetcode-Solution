class Solution {
public:
    
     vector<int> findDiagonalOrder(vector<vector<int>>& a) {
         
         map< int, priority_queue< pair< int, int> > > m;
         vector< int> ans;
         
         for( int i=0;i<a.size();i++){
             for( int j=0;j<a[i].size();j++){
                 
                 m[i+j].push({i,a[i][j]});
             }
         }
         
         for( auto t:m){
             priority_queue<pair<int,int>> pq=t.second;
             while(!pq.empty()){
                 ans.push_back(pq.top().second);
                 pq.pop();
             }
         }
         return ans;
    }
    /*
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        
        int r=a.size();
        int c=a[0].size();
        
        //   
        int i=0,j=0;
        vector< int> ans;
        
        for(int in=0;in<r;in++) {
            // c=max(c,a[in].size());
            if(c < a[in].size()) c=a[in].size();
            i=in,j=0;
            while( i>=0 ){

                if(j<a[i].size()){
                    ans.push_back(a[i][j]);
                    a[i][j]=-1;
                }
                i--;
                j++;
            }
        }
        
        for( int in=1;in<c;in++){
            i=r-1,j=in;
            
            while( i>=0){
                if(j<a[i].size() && a[i][j]!=-1 ) ans.push_back(a[i][j]);
                i--;
                j++;
            }
        }
        return ans;
    }
    */
};