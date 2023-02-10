import java.util.*;

public class hashTable{

	protected LinkedList<hashNode<String, Integer>>[] table;
	protected int size;

	protected class hashNode<String, Integer>{
		protected String key;
		protected int value;
		public hashNode(String myKey, int myValue){
			key = myKey;
			value = myValue;
		}
	}

	public hashTable(int mySize){
		table = new LinkedList[mySize];
		size = mySize;
	}

	public int hash(String myKey){
		int hashVal = 0;
		int tmp = myKey.hashCode() % size;
		if (tmp < 0){
			hashVal = size+tmp;
		} else {
			hashVal = tmp;
		}
		return hashVal;
	}

	public void add(String myKey, Integer myValue){
		hashNode<String, Integer> node = new hashNode(myKey, myValue);
		int h = hash(myKey);
		if (table[h] == null){
			table[h] = new LinkedList<hashNode<String, Integer>>();
		}
		table[h].add(node);
	}
	public void print(){
		for (LinkedList<hashNode<String, Integer>> list : table){
			if (list != null){
				for (hashNode node : list){
					System.out.println(node.key+": "+node.value);
				}
			}
		}
	}
}