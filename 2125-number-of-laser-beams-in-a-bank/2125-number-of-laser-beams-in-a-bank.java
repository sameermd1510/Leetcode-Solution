class Solution {
    public int numberOfBeams(String[] b) {
        
        int pre=0,ans=0;
        
        for( int i=0;i<b.length;i++){
            int cnt=0;
            for(char ch:b[i].toCharArray()){
                if(ch=='1') {
                    cnt++;
                }
            }
            
            if(pre!=0 && cnt!=0){
                ans+=pre*cnt;
            }
            if(cnt!=0)
            pre=cnt;
            //System.out.println(cnt);
        }
        return ans;
    }
}