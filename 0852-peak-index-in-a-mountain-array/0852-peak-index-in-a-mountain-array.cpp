class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        
        int l=0,r=a.size()-1;
        
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(m>0 && m<a.size()-1 && a[m]>a[m-1] && a[m]>a[m+1]) return m;
            else if(a[m]<a[m+1]){
                l=m+1;
            }
            else r=m-1;
        }
        return l;
    }
};