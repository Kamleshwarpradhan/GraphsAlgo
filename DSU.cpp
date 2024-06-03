#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    int size;
    vector<int> rank,parent;

    DisjointSet(){
        rank.resize(size);
        parent.resize(size);
        for(int i=0;i<size;i++){
            rank[i] = 0;
        }
        for(int i=0;i<size;i++){
            parent[i] = i;
        }
    }

    
    // Find function with path compression
    int find(int u){
        if(u==parent[u]){
            return u;
        }

        return parent[u] = find(parent[u]);
    }


    // Union function
    void unionByrank(int u,int v){
        int u_parent = find(u);
        int v_parent = find(v);

        if(u_parent == v_parent) return;

        if(rank[u_parent]>rank[v_parent]){
             parent[v_parent] = u_parent;
        }else if(rank[v_parent]>rank[u_parent]){
            parent[u_parent] = v_parent;
        }else{
            // rank is same so make anyone as parent
            parent[v_parent] = u_parent;
            rank[u_parent] += 1;
        }
    }
};
