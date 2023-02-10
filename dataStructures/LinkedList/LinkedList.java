public class LinkedList{
	public class Node{
		protected int data;
		protected Node next;
		public Node(int data){
			this.data = data;
			this.next = null;
		}
	}
	protected Node first = null;

	public void appendToTail(int data){
		Node node = new Node(data);
		if (first == null){
			first = node;
		} else {
			Node currNode = first;
			while (currNode.next!=null){
				currNode = currNode.next;
			}
			currNode.next = node;
		}
	}

	public void remove(int data){
		if (first != null){
			if (first.data == data){
				first = first.next;
			} else {
				Node currNode = first;
				Node prevNode = first;
				while (currNode.data != data && currNode.next != null){
					prevNode = currNode;
					currNode = currNode.next;
				}
				prevNode.next = currNode.next;
			}
		}
	}

	public void print(){
		if (first!=null){
			Node currNode = first;
			while(currNode!=null){
				System.out.print(currNode.data+" ");
				currNode = currNode.next;
			}
		}
	}
}