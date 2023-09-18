class Solution {
public:
    
    int db(int x){
        return x*x;
    }
    vector<int> sortedSquares(vector<int>& a) {
        
        vector< int> ans;
        int in=-1;
        for( int i=0;i<a.size();i++){
            if(a[i]>=0){
                in=i;
                break;
            }
        }
        if(in==-1){ 
            for( int &x:a) x=x*x;
            for( int i=0;i<a.size()/2;i++){                
                swap(a[i],a[a.size()-i-1]);
            }
            return a;   
        }
        else if( in==0){
            for( int &x:a) x=x*x;
            
            return a;
        }
        else{
            int j=in-1,i=in;
            while( i<a.size() || j>=0){
                
                if(i<a.size() && j>=0){
                    if(db(a[i]) < db(a[j]) )  ans.push_back(db(a[i++]));
                    else ans.push_back(db(a[j--]));
                }
                else if(i<a.size()){
                    ans.push_back(db(a[i++]));
                }
                else ans.push_back(db(a[j--]));
            }
            
        }
        return ans;
    }
};