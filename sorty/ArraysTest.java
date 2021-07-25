package sorty;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;


public class ArraysTest {
	final static int N = 10;
	
	public static int minJump(int []arr) {
		
		
		return 0;
	}
	
	public static void main(String[] args) {
		Integer[] arr = {1,3,2,0,4,6,5};
		Integer[] arr1 = new Integer[10];
		
		//深拷贝
		System.arraycopy(arr, 0, arr1,0, arr.length);	
		
		
//		Arrays.sort(arr);
		Arrays.sort(arr,Collections.reverseOrder());
		
		boolean isequal = Arrays.equals(arr, arr1);
		System.out.println(isequal);
		
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+ "-"+arr1[i]);
			System.out.println();
		}
		System.out.println();
		
	}

}
