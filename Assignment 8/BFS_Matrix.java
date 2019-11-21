import java.util.*;
import java.io.*;
class BFS_Matrix
{   
	private int V;  
    private int adj[][]; 
	BFS_Matrix(int v) 
	{ 
		V = v; 
		adj =new int[v][v]; 
	}  
	void addEdge(int v, int w) 
	{ 
        adj[v][w]=1;  
	}  
	void BFSUtil(int v,boolean visited[]) 
	{  
        
        Queue arr= new LinkedList<Integer>();
        arr.add(v);
        visited[v] = true;
        while(!arr.isEmpty()){ 
            int m=(int)arr.peek();
            System.out.print(m+" ");
            arr.poll();
	    	for(int i=0;i<V;i++) 
	    	{
               if(adj[m][i]==1&&visited[i]==false){
                   arr.add(i);
               }
           }
        }
	}  
	void BFS(int v) 
	{  
        boolean visited[] = new boolean[V]; 
		BFSUtil(v, visited); 
	} 

	public static void main(String args[]) 
	{ 
		BFS_Matrix g = new BFS_Matrix(6); 
        
		g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);
          

		System.out.println("Following is Depth First Traversal "+ 
						"(starting from vertex 2)"); 

        g.BFS(0); 
        // System.out.println(Arrays.toString(arr));
	} 
}  
