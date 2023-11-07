class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        priority_queue< double, vector< double> , greater<double>> pq;
        
        for( int i=0;i<dist.size();i++){
            pq.push( (double)dist[i] /(speed[i]*1.0) );
        }
        int c=0;
        int min=0;
        
        while(!pq.empty()){
            double x=pq.top();
            pq.pop();
            //cout<<x<<" ";
            if( (x-min*1.0)*10> 0 ){
                c++;
                min++;
            }
            else break;
        }
        return c;
    }
};