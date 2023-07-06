class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        
        int ans=INT_MAX,i=0,j=0,sum=0;
        while(i<a.size()){
            sum+=a[i];
            
            while(sum>=t){
                ans=min(ans, i-j+1);
                sum-=a[j++];
            }
            i++;
        }
        return ans==INT_MAX ?0:ans;
    }
};