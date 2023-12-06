class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        unordered_map<  int ,  int> m;
        
        for( int x:a) m[x]++;
        
        int ans=0;
        
        for( int i=0;i<a.size();i++){
            
            if(!m.count(a[i])) continue;
            
            if(m.find(k-a[i])!=m.end() && m[k-a[i]] >0 ){
                
                if(k==2*a[i] && m[a[i]] <2) continue;
                m[a[i]]--;
                m[k-a[i]]--;
                
                if(m[a[i]]==0) m.erase(a[i]);
                
                if( 2*a[i]!=k && m[k-a[i]]==0) m.erase(k-a[i]);
                
                ans++;
            }
        }
        return ans;
        
    }
};