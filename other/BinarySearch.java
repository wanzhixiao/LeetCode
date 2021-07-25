package other;

class Solusion{
	public int binarySearch(int[] arr,int key) {
		int left = 0,right = arr.length;
		while(left<right)
		{
			int mid = left+right>>1;
			if(arr[mid]==key) {
				return arr[mid];
			}else if(arr[mid]<key) {
				left = mid+1;
			}else {
				right = mid;
			}
		}
		return -1;
	}
	
	public static int findBigger(int[] arr,int key) {
		int left = 0,right = arr.length;
		int pos = 0;
		while(left<=right)
		{
			int mid = left+right>>1;
			if(arr[mid]==key) {
				break;
			}
			else if(arr[mid]>key) {
				pos = mid;
				right = mid-1;
			}else {
				left = mid+1;
			}
		}	
//		pos = (pos==0)?1:pos;
//		pos = (pos==arr.length)?arr.length-1:pos;
		return arr[pos];
	}
	
	public static int findSmaller(int[] arr,int key) {
		return 0;
	}
}

public class BinarySearch {
	public static void main(String[] args) {
		Solusion s = new Solusion();
		int[] arr = {1,3,4,7,8,9};
		int key = 7;
		System.out.println(s.findBigger(arr, key));
		
	}
}
