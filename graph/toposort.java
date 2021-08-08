package graph;


import java.util.*;


class Solution11{
    int[] degree;
    ArrayList<ArrayList<Integer>> graph;

    boolean circularArrayLoop(int[] nums){
        int n = nums.length;
        degree = new int[n];
        graph = new ArrayList<ArrayList<Integer>>();

        for(int i=0; i<n; i++){
            graph.add(new ArrayList<>());
        }
        //建图
        for(int i=0; i<n; i++){
            int end = ((i+nums[i])%n+n)%n;
            if(nums[i]<=0 || i==end) continue;
            graph.get(i).add(end);
            degree[end]++;
        }
        if(toposort(n)){
            return true;
        }
        graph.clear();

        for(int i=0; i<n; i++){
            graph.add(new ArrayList<>());
        }
        //建图
        for(int i=0; i<n; i++){
            int end = ((i+nums[i])%n+n)%n;
            if(nums[i]>=0 || i==end) continue;
            graph.get(i).add(end);
            degree[end]++;
        }
        return toposort(n);
    }

    boolean toposort(int n){

        Queue<Integer> q = new LinkedList<>();
        //将度为0的结点加入队列
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.offer(i);
            }
        }
        //逐一删除与度为0相邻结点的连边，并将新的度为0的结点加入队列
        while(!q.isEmpty()){
            int cur = q.poll();
            for(Integer neigh: graph.get(cur)){
                degree[neigh]--;
                if(degree[neigh]==0){
                    q.offer(neigh);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(degree[i] != 0){     //若还存在入度为0的结点,则说明存在环
                return true;
            }
        }
        return false;
    }
}

public class toposort {
    public static void main(String[] args) {
        int []nums = {-2,1,-1,-2,-2};
        Solution11 solu = new Solution11();
        boolean res = solu.circularArrayLoop(nums);
        System.out.println(res);
    }
}
