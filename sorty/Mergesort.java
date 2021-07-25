package sorty;

import java.util.Scanner;

public class Mergesort {
	
	static int N = 101;
	static int count = 0;
	
	public static void main(String[] args) {
		int[] arr = new int[N];
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		
		for(int i=0;i<n;i++) {
			arr[i] = scanner.nextInt();
		}
		
		int[] tmp = new int[N];
		
		mergesort(arr,0,n-1,tmp);
		
		for(int i=0;i<n;i++) {
			System.out.print(arr[i]+" ");
		}
		
		System.out.println(count);
		scanner.close();
	}
	
	public static void mergesort(int [] arr,int left,int right,int[] tmp) {
		if(left>=right) {
			return;
		}
		int mid = left+(right-left)/2;
		mergesort(arr, left, mid,tmp);
		mergesort(arr, mid+1, right,tmp);
		merge(arr, left, mid,right,tmp);
	}
	public static void merge(int []arr,int left,int mid,int right,int[] tmp) {
		int i=left,j=mid+1,k=0;
		while(i<=mid && j<=right) {
			if(arr[i]<arr[j]) {
				tmp[k++] = arr[i++];
			}else {
				count += mid-i+1;
				tmp[k++] = arr[j++];
			}
		}
		
		while(i<=mid) {
			tmp[k++] = arr[i++];
		}
		while(j<=right) {
			tmp[k++] = arr[j++];
		}
		for(int p=0;p<k;p++) {
			arr[left+p] = tmp[p];
		}
	}
}
