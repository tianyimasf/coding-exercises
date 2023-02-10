public class Node{
	int data;
	boolean marked;
	Node[] adjacent_nodes;
	public Node(int data, int n){
		this.data = data;
		this.marked = false;
		this.adjacent_nodes = new Node[n];
	}
}