package com.meituan0829;

import java.io.*;
import java.util.*;

public class MTMain1 {
    static int TOTAL = 100000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();
        String[] degree = str.split(" ");
        int[] arr = new int[n];
        int[] brr = new int[n];
        int[] dp = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(degree[i]);
            brr[i] = Integer.parseInt(degree[i]);
        }

        int count = 0;
        Arrays.sort(arr);

        dp[0] = 0;
        for(int i=1;i<n;i++){
            if(brr[i] > arr[i]){
                count++;
            }
            if(brr[i]>=arr[i]){
                dp[i] = dp[i-1]+count;
            }else{
                dp[i] = dp[i-1];
            }
        }
        System.out.println(dp[n-1]);
    }
}
