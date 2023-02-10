import java.util.*;

public class arrayList{
	protected int size;
	protected Object[] str_list;

	public arrayList(){
		size = 0;
		str_list = new Object[2];
	}

	public void add(Object str){
		if (size < str_list.length){
			str_list[size] = str;
			size++;
		} else {
			Object[] str_list_new = Arrays.copyOf(str_list, size*2);
			str_list = str_list_new;
			str_list[size] = str;
			size++;
		}
	}

	public void print(){
		for (int i = 0; i < size; i++){
			System.out.print(str_l ist[i]+" ");
		}
	}
}