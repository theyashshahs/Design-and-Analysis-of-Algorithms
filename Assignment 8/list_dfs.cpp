#include<bits/stdc++.h>

using namespace std; 

class Graph 
{ 
    int v;    

    list<int> *adj; 

    void DFS_list(int v, bool visited[]); 

public:

    Graph(int v);  

    void addEdge(int v, int w); 
  
    void DFS(int v); 
}; 
  
Graph::Graph(int v) 
{ 
    this->v = v; 

    adj = new list<int>[v]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
} 
  
void Graph::DFS_list(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 
  
    list<int>::iterator i; 

    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFS_list(*i, visited); 
} 

void Graph::DFS(int v) 
{ 
   
    bool *visited = new bool[v]; 
    for (int i = 0; i < v; i++) 
        visited[i] = false; 
  
    DFS_list(v, visited); 
} 
  
int main() 
{ 
    Graph g(6); 
 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(1, 4);
    g.addEdge(1, 0);
    g.addEdge(2, 0); 
    g.addEdge(2, 1);
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 4);
  
    cout << "DFS (starting from vertex 3) \n"; 
    g.DFS(3); 
  
    return 0; 
} 