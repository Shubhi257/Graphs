#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this -> V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycleDFS(int src, int par, vector<bool>&vis){
        vis[src] = true;
        list<int> neigh = l[src];

        for(int V : neigh){
            if(!vis[V]){
                if(isCycleDFS(V, src, vis)){
                    return true;
                }
            }
            else if(V != par){
                return true;
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++){
            /* code */
            if(!vis[i]){
                if(isCycleDFS(1, -1,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    cout<<g.isCycle()<<endl;
    
    return 0;
}