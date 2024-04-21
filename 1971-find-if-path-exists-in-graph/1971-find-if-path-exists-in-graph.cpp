class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int start, int end) 
    {
        vector< vector< int> > adj(n);
        if(start==end) return true;
        
        for(int i=0;i<e.size();i++)
        {
            adj[e[i][0]].push_back(e[i][1]);
            
            adj[e[i][1]].push_back(e[i][0]);
        }
        
        //if( find(adj[start].begin() , adj[start].end() ,end) !=adj[start].end()) return true;
        
        queue< int> q;
        
         vector< bool> vis(n,false);
        
        q.push(start);
        vis[start]=true;        
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            
            vis[x]=true;
            
            if(x==end) return true;
            
            for(auto t=adj[x].begin() ;t!=adj[x].end();t++)
            {
                if(!vis[*t])
                {
                    q.push(*t);
                    vis[*t]=true;
                    if(*t==end) return true;
                }
            }
        }
        
        return false;
    }
};