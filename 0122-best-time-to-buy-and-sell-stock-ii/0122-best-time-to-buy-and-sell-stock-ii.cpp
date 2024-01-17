class Solution {
public:
    int dp[100000+1];
    int maxProfit(vector<int>& p) 
    {
        
        if(p.size()==1) return 0;
        if(p.size()==2) return max(0,p[1]-p[0]);
        
        int ans=0,x=0;
        
        for(int i=0; i<p.size()-1;i++)
        {
            if(p[i+1]-p[i] <0) continue;
            ans=ans+p[i+1]-p[i];
        }
        return ans;
        /*
        // using Dynamic program.
        
        if(p.size()==1) return 0;
        if(p.size()==2) return max(0,p[1]-p[0]);
        dp[0]=0;  
        dp[1]=0;
        dp[2]=(p[1]>p[0]) ? (p[1]-p[0]): 0;
        for(int i=3;i<=p.size();i++)
        {
            if(p[i-1] <p[i-2])
            dp[i]=dp[i-1];
            else
            dp[i]=dp[i-1]+p[i-1]-p[i-2];
        }
        return dp[p.size()];
        */
    }
};