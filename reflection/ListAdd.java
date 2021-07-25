package reflection;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

/**
 * @author XWZ
 *
 */
public class ListAdd {
	/**
	 * @param args
	 * @throws NoSuchMethodException
	 * @throws SecurityException
	 * @throws IllegalAccessException
	 * @throws IllegalArgumentException
	 * @throws InvocationTargetException
	 */
	public static void main(String[] args) throws NoSuchMethodException, SecurityException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		ArrayList<Integer> list = new ArrayList<>();
		Class<? extends List> cz = list.getClass();
		Method method = cz.getDeclaredMethod("add", Object.class);
		method.invoke(list, 12);
		System.out.println(list);
		
		
		//初始化泛型
		Generic<Integer> genericInteger = new Generic<Integer>(123456);
		System.out.println(genericInteger.getKey());
		
	}
}


class Generic<T>{
	private T key;
	public Generic(T key) {
		this.key = key;
	}
	
	public T getKey() {
		return key;
	}
}


