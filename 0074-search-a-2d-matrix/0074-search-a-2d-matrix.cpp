class Solution {
public:
    /*bool searchMatrix(vector<vector<int>>& m, int t) 
    {
        int r=m.size(),c=m[0].size();
        for(int i=0;i<r;i++)
        {
            if(m[i][0] <=t && m[i][c-1]>=t)
            {
                auto it=lower_bound(m[i].begin(),m[i].end(),t);
                if(it!=m[i].end() && *it==t) return true;
                else return false;
            }
            else if(m[i][0] >t) return false;
        }
        return false;
    }*/
    bool searchMatrix(vector<vector<int>>& m, int t) 
    {
        int r=m.size(),c=m[0].size();
        
        int R=0,C=c-1;
        while(R<r && C>=0){
            if(m[R][C]==t) return true;
            else if(m[R][C] > t) C--;
            else R++;
        }
        return false;
    }
};