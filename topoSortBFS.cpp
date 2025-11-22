#include<bits/stdc++.h>
using namespace std;

class Graph{

    int V;
    list<int> *l;

    public:
    Graph(int V){
        this-> V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
    }

    void topoSortBFS(){
        vector<int> res;

        //1. calculate the indegree
        vector<int> indegree(V,0);
        for(int u=0; u<V; u++){
            for(int v: l[u]){
                indegree[v]++;
            }
        }

        //2. 0 indegree push to Queue
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }       
        }

        //3. bfs
        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int v: l[curr]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        //printing the result
        for(int val: res){
            cout<<val<<" ";
        }

        cout<<endl;
    }

};

int main(){

    Graph g(6);

    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    g.topoSortBFS();

    
    return 0;
}