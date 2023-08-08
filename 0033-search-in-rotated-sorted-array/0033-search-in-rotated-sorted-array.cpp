class Solution {
public:
    int search(vector<int>& n, int t) 
    {
        if(n.size()==1 ) return (n[0]==t) ?0 :-1;
        
        int l=n.size();
        int lb=0,ub=l-1;
        
        while(lb<=ub && lb<l && ub>0)
        {
            if(n[lb]==t) return lb;
            
            if(n[ub]==t) return ub;
            
            lb++;
            ub--;
        } 
        return -1;
    }
};