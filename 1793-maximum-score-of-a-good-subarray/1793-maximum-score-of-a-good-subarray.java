class Solution {
    public int maximumScore(int[] a, int k) {
        
        Stack< Integer> st=new Stack< Integer>();
        int ans=0;
        
        // 1 3
        int i;
        for( i=0;i<a.length;i++){
            while(!st.isEmpty() && a[st.peek()] >=a[i]){
                int h=a[st.peek()];
                st.pop(); 
                int left=(st.isEmpty())? -1 :st.peek();
                if( k<i && k> left ) ans=Math.max(ans, h*(i-left-1));
            }
            st.push(i);
        }
        while(!st.isEmpty() && a[st.peek()]>=0 ){
            int h=a[st.peek()];
            st.pop();
            int left=(st.isEmpty())?-1:st.peek();
            if(k<i && k> left) ans=Math.max(ans , h*(i-left-1));
        }
        return ans;
    }
}