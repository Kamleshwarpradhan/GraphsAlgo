/*By Dijkstra we can find shortest path from a single source to all other nodes.*/
/*Applicable only for the graph having no negative weight 
  or negative weight cycle*/

/* To implement Dijksta we will use set or priority_queue 
   As basic funda of Dijkstra is We want to select the 
   Shortest(min weight-path) as soon as possible so by using min-heap we can do it effeciently.*/

/* When we can use BFS kind of approach like we did to find
    shortest path in a graph having all the edge-weight equal to unit but using BFS lead us to so much unnecessary insertion of nodes in queue (DRY RUN...) 
*/

/*-----------------Priority_queue Based-------------------*/
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //Priority Queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(V);
        for(int i=0;i<V;i++){
            dis[i]=1e9;
        }
        dis[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
           int dist = pq.top().first;
           int node = pq.top().second;
           pq.pop();
            for(auto it:adj[node]){
                int wt = it[1];
                int adjacent = it[0];
                if(dist+wt<dis[adjacent]){
                    dis[adjacent] = dist + wt;
                    pq.push({dis[adjacent],adjacent});
                }
            }
        }
        return dis;
}   

/*-----------------Set Based-------------------*/
/*It will help us to remove some unnecessary checks if we already get the shortest distance for a particular edge*/
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        set<pair<int,int>>s;
        //      {node,distance}
        s.insert({S,0});
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i] = 1e9;
        }
        dist[S] = 0;
        while(!s.empty()){
            auto it = *(s.begin());
            int node = it.first;
            int dis = it.second;
            s.erase(it);
            for(auto it:adj[node]){
                int wt = it[1];
                int adjacent = it[0];
                if(dis+wt<dist[adjacent]){
                    if(dist[adjacent]!=1e9){ // Remove the unnecessary entry
                        s.erase({adjacent,dist[adjacent]});
                    }
                    dist[adjacent] = dis + wt;
                    s.insert({adjacent,dis+wt});
                }
            }
        }
        return dist;
}