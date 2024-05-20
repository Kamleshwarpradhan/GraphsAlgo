void bfs(int src,vector<int> adj[]){
        queue<int>q;
        vector<int>vis(V,0);
        q.push(src);
        vis[src] = 1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            // visit all non-visited neighbour
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }        
}