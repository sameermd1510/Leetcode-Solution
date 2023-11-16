class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &a) {
		sort(a.begin(), a.end());
        vector<vector<int> > res;
		vector<int> vec;
		subsetsWithDup(res, a, vec, 0);
		return res;
    }
private:
	void subsetsWithDup(vector<vector<int> > &res, vector<int> &a, vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != a.size(); ++i)
			if (i == begin || a[i] != a[i - 1]) { 
				vec.push_back(a[i]);
				subsetsWithDup(res, a, vec, i + 1);
				vec.pop_back();
			}
	}
};