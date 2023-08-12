class Solution {
public:
    
    int rangeBitwiseAnd(int l, int r) {
        if(l==0 || r==0) return 0;
        if(l==r) return l;
        /*
        011
        100
        101
        
        */
        int ans=0;
        while(l!=0 && r!=0){
            int f=(int)pow(2,(int)log2(l));
            int s=(int)pow(2,(int)log2(r));
            if((f&s)==0) return ans;
            l=l^f;
            r=r^s;
            ans+=(f&s);
        } 
        return ans;
    }
};