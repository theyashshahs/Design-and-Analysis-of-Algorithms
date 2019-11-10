#include<bits/stdc++.h>
  
using namespace std; 
   
class Graph 
{ 
    int v;    

    list<int> *adj;

public: 
    Graph(int v);   
    
    void addEdge(int v, int w);  
   
    void BFS(int s);   
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
  
void Graph::BFS(int s) 
{ 
    
    bool *visited = new bool[v]; 
    for(int i = 0; i < v; i++) 
        visited[i] = false; 
  
    
    list<int> list_q;  
   
    visited[s] = true; 
    list_q.push_back(s); 
  

    list<int>::iterator i; 
  
    while(!list_q.empty()) 
    { 

        s = list_q.front(); 
        cout << s << " "; 
        list_q.pop_front(); 
  
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                list_q.push_back(*i); 
            } 
        } 
    } 
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

    cout << "BFS (starting from vertex 3) \n"; 
    g.BFS(3); 
  
    return 0; 
} 