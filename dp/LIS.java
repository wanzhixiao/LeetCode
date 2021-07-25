package dp;

import java.util.Scanner;

public class LIS {
	static int N=1001;
	public static int LIS(int[] arr) {
		int max = 1;
		int[] d = new int[arr.length];
		for(int i = 0; i < arr.length; i++) {
			int tmax = 1;
			for(int j = 0; j < i; j++) {
				tmax = (arr[i] > arr[j] && tmax < d[j]+1) ? d[j]+1: tmax;
			}
			d[i] = tmax;
			max = (max < d[i]) ? d[i]: max;
		}
		return max;
	}
	
	public static void main(String[] args) {
	
		Scanner scanner=new Scanner(System.in);
		int n=scanner.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
			arr[i]=scanner.nextInt();
		int result=LIS(arr);
		System.out.println(result);
		scanner.close();
	}
}
