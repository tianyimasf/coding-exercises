public class Graph{

	Node[] nodes;
	int nodes_num;

	public Graph(int n){
		nodes_num = n;
		nodes = new Node[n];
	}

	public void addNode(Node a){
		int a_data = a.data;
		nodes[a_data] = a;
	}

	// add an array of nodes all at once
	public void addNodes(Node[] a){
		for (int i = 0; i < a.length; i++){
			int a_data = a[i].data;
			nodes[a_data] = a[i];
		}
	}

	// directed
	public void addEdge(Node a, Node b){
		int a_data = a.data;
		int b_data = b.data;
		a.adjacent_nodes[b_data] = b;
	}

	public int arrLength(int[] arr){
		int count = 0;
		for (int i = 0; i < arr.length; i++){
			if (arr!=null){
				count++;
			}
		}
		return count;
	}

	public void print(){
		for (int i = 0; i < nodes_num; i++){
			if (nodes[i]!=null){
				Node node = nodes[i];
				System.out.print(node.data+" adjacent_nodes: ");
				for (int j = 0; j < nodes_num; j++){
					if (node.adjacent_nodes[j]!=null){
						System.out.print(node.adjacent_nodes[j].data+" ");
					}
				}
				System.out.println();
			}
		}
	}
}