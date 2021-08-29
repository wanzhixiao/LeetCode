package com.meituan0829;
import java.util.*;


public class Two {
    static long ans = 0;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()){
            int n = scanner.nextInt();
            int[] book = new int[n];
            for (int i = 0; i < n; i++) {
                book[i] = scanner.nextInt();
            }
            int[] desk = new int[n];
            for (int i = 0; i < n; i++) {
                desk[i] = scanner.nextInt();
            }
            ans = permute(desk,book);
            System.out.println(ans);
        }
    }


    public static long permute(int[] nums,int[] book) {

        int len = nums.length;
        Deque<Integer> path = new ArrayDeque<>();
        boolean[] visited = new boolean[len];
        if(len == 0){
            return ans;
        }
        dfs(nums,len,0,path,visited,book);
        return ans;
    }

    public static void dfs(int[] nums, int len, int depth, Deque<Integer> path, boolean[] visited,int[] book){
        if(depth == len){
            int cnt = 0;
            for (int j = 0; j < book.length; j++) {
                if(new ArrayList<>(path).get(j) >= book[j]){  //书架宽度 > 书的宽度
                    cnt++;
                }
            }
            if(cnt == book.length){
                ans += 1;
            }
            return;
        }
        for (int i = 0; i < len; i++) {     //任何一个位置都可以放
            if(!visited[i]){
                path.addLast(nums[i]);
                visited[i] = true;
                //排列这里是depth+1而不是i+1
                dfs(nums,len,depth+1,path,visited,book);
                visited[i] = false;
                path.removeLast();
            }
        }
    }
}