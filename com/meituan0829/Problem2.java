package com.meituan0829;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.Scanner;

public class Problem2 {
    public static long ans;
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] book = new int[n];
        int[] desk = new int[n];
        for(int i=0;i<n;i++){
            book[i] = sc.nextInt();
        }
        for(int i=0;i<n;i++){
            desk[i] = sc.nextInt();
        }
        backtrack(book,desk);
        System.out.println(ans);

    }
    public static void backtrack(int[] book, int[] desk){
        int n = book.length;
        if(n == 0){
            return;
        }
        Deque<Integer> deque = new ArrayDeque<>();
        boolean[] visited  = new boolean[n];
        dfs(book,desk,visited,deque,0,n);

    }

    public static void dfs(int[] book, int[] desk,boolean[] visited, Deque<Integer> deque,int depth,int n){
        //判断是否满足条件
        if(depth == n){     //所有的桌子都被占用
            int cnt = 0;       //记下desk[i]>book[i]的数量
            ArrayList<Integer> arr = new ArrayList<>(deque);
            for(int j=0;j<n;j++){
                if(arr.get(j)>=book[j]){
                    cnt++;
                }
            }
            if(cnt == n){
                ans++;
            }
            return;
        }
        //枚举遍历
        for(int i=0;i<n;i++){
            if(!visited[i]){//如果桌子没被使用,剪枝
                //做决定
                visited[i] = true;
                deque.addLast(desk[i]);
                //尝试
                dfs(book,desk,visited,deque,depth+1,n);
                //撤销决定
                deque.removeLast();
                visited[i] = false;
            }
        }
    }
}
