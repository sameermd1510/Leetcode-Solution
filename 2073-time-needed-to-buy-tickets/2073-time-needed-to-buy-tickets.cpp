class Solution {
public:
    int timeRequiredToBuy(vector<int>& tick, int k) {
        
        queue< pair< int, int> > q;
        
        for( int i=0 ; i < tick.size() ; i++ ) {
            q.push({i, tick[i] });    
        }
        int time=0;
        while( !q.empty()){
            
                auto t=q.front();
                q.pop();
            
                if( t.first==k && t.second==1) return time+1;
                
                if(t.second>1)
                q.push( { t.first , t.second-1 } );
                time++;
            
            if(q.size()==1) return q.front().second+time;
        }
        return time;
    }
};