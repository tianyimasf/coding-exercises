import java.util.*;

public class Test{
	public static void DFS(Node node){
		System.out.println("Node "+node.data);
		node.marked = true;
		for (int i = 0; i < node.adjacent_nodes.length; i++){
			Node adj_node = node.adjacent_nodes[i];
			if (adj_node!=null){
				if (adj_node.marked == false){
					DFS(adj_node);
				}
			}
		}
	}

	public static void BFS(Node root){
		Queue<Node> q = new LinkedList<>();
		root.marked = true;
		q.add(root);

		while(!q.isEmpty()){
			Node node = q.remove();
			System.out.println("Node "+node.data);
			for(int i = 0; i<node.adjacent_nodes.length; i++){
				Node adj_node = node.adjacent_nodes[i];
				if (adj_node!=null){
					if (adj_node.marked==false){
						adj_node.marked = true;
						q.add(adj_node);
					}
				}
			}
		}
	}

	public static void resetGraphSearch(Graph g){
		Node[] nodes = g.nodes;
		for (int i = 0; i < nodes.length; i++){
			if (nodes[i]!=null){
				nodes[i].marked = false;
			}
		}
	}

	public static void main(String[] arg){
		// a graph with nodes with 1 < data <= n, nodes' adjacent nodes list length <= 10
		// example from page.107 of Crack the Technical Interview
		int n = 10;
		Graph g = new Graph(n);
		Node n0 = new Node(0, n);
		Node n1 = new Node(1, n);
		Node n2 = new Node(2, n);
		Node n3 = new Node(3, n);
		Node n4 = new Node(4, n);
		Node n5 = new Node(5, n);
		Node[] nodes = {n0, n1, n2, n3, n4, n5};
		g.addNodes(nodes);
		g.addEdge(n0, n1);
		g.addEdge(n0, n4);
		g.addEdge(n0, n5);
		g.addEdge(n1, n3);
		g.addEdge(n1, n4);
		g.addEdge(n2, n1);
		g.addEdge(n3, n2);
		g.addEdge(n3, n4);
		//g.print();
		System.out.println("DFS");
		DFS(n0);
		System.out.println();
		resetGraphSearch(g);
		System.out.println("BFS");
		BFS(n0);
	}
}