class DFS_Matrix
{ 
	private int V;  
    private int adj[][]; 
	DFS_Matrix(int v) 
	{ 
		V = v; 
		adj =new int[v][v]; 
	}  
	void addEdge(int v, int w) 
	{ 
        adj[v][w]=1;  
	}  
	void DFSUtil(int v,boolean visited[]) 
	{  
        System.out.print(v+" ");
        visited[v] = true; 
		 
		for(int i=0;i<V;i++) 
		{
            if(adj[v][i]==1&&visited[i]==false){
                DFSUtil(i,visited);
            }
        }
        
	}  
	void DFS(int v) 
	{  
		boolean visited[] = new boolean[V]; 
		DFSUtil(v, visited); 
	} 

	public static void main(String args[]) 
	{ 
		DFS_Matrix g = new DFS_Matrix(6); 

		g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
          

		System.out.println("Following is Depth First Traversal "+ 
						"(starting from vertex 2)"); 

        g.DFS(0); 
        System.out.println();
	} 
}  
