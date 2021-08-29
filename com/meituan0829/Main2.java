package com.meituan0829;


import java.io.*;
import java.util.Arrays;

public class Main2 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String arr = br.readLine();
        String[] a = arr.split(" ");
        arr = br.readLine();
        String[] b = arr.split(" ");

        int[] aa = new int[n];
        int[] bb = new int[n];

        for(int i=0;i<n;i++) {
            aa[i] = Integer.parseInt(a[i]);
            bb[i] = Integer.parseInt(b[i]);
        }
        Arrays.sort(aa);
        Arrays.sort(bb);




    }
}
