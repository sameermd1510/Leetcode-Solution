class Solution {
public:
    vector<vector<int>> permute(vector<int>& n) 
    {
        vector< vector<int> > ans;
        //ans.push_back(n);
        sort(n.begin(),n.end());
    do
    {
        ans.push_back(n);
    }while(next_permutation(n.begin(),n.end()));
      
        return ans;
    }
};