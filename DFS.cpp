void dfs(int src,vector<int> &vis,vector<int> adj[]){
        vis[src] = true;

        // Visit all non-visited neighbour
        for(auto nbr:adj[src]){
            
            if(!vis[nbr]){
                dfs(nbr,vis,adj,ans);
            }
        }
    }