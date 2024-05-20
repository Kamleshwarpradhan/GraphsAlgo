// DFS based check
    bool dfsCheck(int src,int parent,vector<int> &vis,vector<int> adj[]){
        vis[src] = true;
        
        for(auto nbr:adj[src]){
            // if neighbour is not visited then it is okay go visit
            if(!vis[nbr]){
                if(dfsCheck(nbr,src,vis,adj)==true){
                    return true;
                }
            }else if(nbr != parent){ // but if neighbour already visited and neighbour is not the parent
                                    // so definetly someone already visited this node and we came again so
                                    // cycle is present in graph...
                return true;
            }
        }
        return false;
    }
    
    
    // BFS based check
    bool bfsCheck(int src,vector<int> &vis,vector<int> adj[]){
        
        
        // Here to maintain parent we push two entities in queue i.e. {src,parent}
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src] = true;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int node = it.first;
            int parent = it.second;
            
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push({nbr,node});
                }else if(nbr != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfsCheck(i,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }