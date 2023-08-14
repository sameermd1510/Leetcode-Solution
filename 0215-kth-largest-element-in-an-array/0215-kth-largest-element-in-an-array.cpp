class Solution {
public:
    int findKthLargest(vector<int>& a, int k) 
    {
        priority_queue<int> pq(a.begin(),a.end());
        
        while(!pq.empty() && --k!=0){
            pq.pop();
        }
        return pq.top();
    }
};