package com.meituan0829;
import java.util.*;

public class OneTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()){
            int n = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
            }
            int sum = 0;
            HashSet<Integer> set = new HashSet<>();
            set.add(arr[0]);
            for (int i = 1; i < n; i++) {
                for(Integer val:set){
                    if(val < arr[i]){
                        sum ++;
                    }
                }
                set.add(arr[i]);
            }
            System.out.println(sum);
        }
    }

}