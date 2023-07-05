class Solution {
public:
    int longestSubarray(vector<int>& a) {
         int k=1;
        
        int i=0,j=0,ans=0,fl=1;
        for( ;i<a.size();i++ ){
            
            if(a[i]==0) fl=0;
            if(a[i]==0) k--;
            
            while(k<0){
                if(a[j++]==0)k++;
            }
            ans=max(ans,i-j+1-abs(k-1));
        }
        //ans=max(ans,i-j+1-abs(k-1));
        return ans-fl;
        
    }
};