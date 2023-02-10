public class Test{
	public static void main(String[] arg){
		LinkedList list = new LinkedList();
		list.appendToTail(1);
		list.appendToTail(2);
		list.appendToTail(3);
		list.appendToTail(4);
		list.print();
		list.remove(2);
		list.print();
	}
}
