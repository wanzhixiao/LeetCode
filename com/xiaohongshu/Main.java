package com.xiaohongshu;

import java.io.*;
import java.util.*;


class Solution{
    int[] direct = {1,-1};
    boolean[][] visited;
    int res = 0;
    public int PathCount(String[] arr,int N,int cnt){
        if(N == 1){
            return 1;
        }
        visited = new boolean[N][N];

        dfs(arr,0,0,N);
        return res;
    }

    public void dfs(String[] arr,int i,int j,int n){
        if(i==n-1 && j==n-1){
            res += 1;
            return;
        }
        if((i<0)||(i>=n)||(j<0)||(j>=n)){
            return;
        }
        if(arr[i].charAt(j) == '#'){
            return;
        }
        if(visited[i][j]){
            return;
        }
        visited[i][j] = true;
//        dfs(arr,i,j,n);
//        dfs(arr,i,j,n);

        //四个方向每次只能控制一个方向动
        for(int p=0;p<2;p++){
            i = i+direct[p];
            dfs(arr,i,j,n);
        }

        for(int p=0;p<2;p++){
            j = j+direct[p];
            dfs(arr,i,j,n);
        }
        visited[i][j] = false;
        return;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int cnt = 0;
        String[] arr = new String[N];
        for(int i=0;i<N;i++){
            String line = sc.next();
            arr[i] = line;
        }

        Solution s = new Solution();
        int res = s.PathCount(arr,N,cnt);

        System.out.println(res);
    }
}
