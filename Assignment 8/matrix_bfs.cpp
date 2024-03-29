#include <bits/stdc++.h> 
using namespace std; 
  
class Graph { 
   
    int v; 
   
    int e; 
  
    int** adj; 
  
public: 

    Graph(int v, int e); 
   
    void addEdge(int start, int e); 
  
    void BFS(int start); 
}; 
   
Graph::Graph(int v, int e) 
{ 
    this->v = v; 
    this->e = e; 

    adj = new int*[v];
     
    for (int row = 0; row < v; row++) { 
        adj[row] = new int[v]; 
        for (int column = 0; column < v; column++) { 
            adj[row][column] = 0; 
        } 
    } 
} 
   
void Graph::addEdge(int start, int e) 
{  
    adj[start][e] = 1; 
    adj[e][start] = 1; 
} 
   
void Graph::BFS(int start) 
{ 
    vector<bool> visited(v, false); 
    vector<int> q; 

    q.push_back(start); 
    visited[start] = true; 
  
    int visit; 

    while (!q.empty()) {
         
        visit = q[0]; 
        cout << visit << " "; 
        q.erase(q.begin()); 
  
        for (int i = 0; i < v; i++) { 
            if (adj[visit][i] == 1 && (!visited[i])) { 

                q.push_back(i); 
  
                visited[i] = true; 
            } 
        } 
    } 
} 
  
int main() 
{ 
    int v = 6, e = 15; // number of vertex and edges respectively
 
	Graph g(v, e); 
	
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

    g.BFS(0); 
} 