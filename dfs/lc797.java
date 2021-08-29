package dfs;


import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class lc797 {

    private static List<List<Integer>> result;
    private static Deque<Integer> stack = new ArrayDeque<Integer>();
    public static List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        result = new ArrayList<>();
        int n = graph.length;
        stack.offerLast(0);
        dfs(graph,0,n);
        return result;
    }

    public static void dfs(int[][] graph,int cur,int n){
        if(cur == n){
            result.add(new ArrayList<>(stack));
            return;
        }
        for(int y:graph[cur]){
            stack.offerLast(y);
            dfs(graph,y,n);
            stack.pollLast();
        }
    }


    public static void main(String[] args) {


        int[][] graph = {{0,1,0,1,1},{0,0,1,1,1},{0,0,0,1,0},{0,0,0,0,1},{0,0,0,0,0}};

        List<List<Integer>> res = allPathsSourceTarget(graph);
        System.out.println(res);

    }
}
