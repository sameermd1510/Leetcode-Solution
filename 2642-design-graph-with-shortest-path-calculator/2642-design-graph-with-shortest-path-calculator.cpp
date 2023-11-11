class Graph {
public:
    Graph(int n, vector<vector<int>>& ed) {
        adj.resize(n);
        
        for( auto& e:ed){
            adj[e[0]].push_back({e[1],e[2]});
        }
        
    }
    
    void addEdge(vector<int> e) {
        
        adj[e[0]].push_back({e[1],e[2]});
        
    }
    
    int shortestPath(int n1, int n2) {
        
        int n=adj.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector< int> v(n,INT_MAX);
        v[n1]=0;
        pq.push({0,n1});
        
       while(!pq.empty()){
           auto t=pq.top();
           int cct=t.first;
           int cn=t.second;
           pq.pop();
           
           if(cct > v[cn]) continue;
           
           if(cn==n2) return cct;
           
           for( auto& x: adj[cn]){
               
               // hera new cost= cct+ x.second(that is cost from parent to child)
               // and x.first is child of parent.
               if( cct+x.second  < v[x.first]){
                   v[x.first]=cct+x.second;
                   pq.push({cct+x.second ,  x.first});
               }
           }
       }
        return -1;
    }
    private :
    vector< vector<pair< int,int>> > adj;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */