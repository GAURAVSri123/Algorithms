#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<list>
using namespace std;

class Graph {
public:
    int V;
    list<int> *l; // int array

    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFS(){
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0] = true;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for(int v:l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }

        }
    }

     void dfsHelper(int u,vector<bool>&vis){
        cout<<u<<" ";
        vis[u] = true;
        for(int v:l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }

     }

    void DFS(){
        int src = 0;
        vector<bool> vis(V,false);
        //dfsHelper(src,vis);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsHelper(i,vis);
            }
        }
    }

    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<":";
            for(int neigh:l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

    ~Graph(){
        delete [] l;
    }

    
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
     g.addEdge(1,2);
      g.addEdge(1,3);
       
        g.addEdge(2,4);

        g.printAdjList();
        cout<<"BFS :";
        g.BFS();
        cout<<endl;
        cout<<"DFS :";
        g.DFS();

    return 0;

}