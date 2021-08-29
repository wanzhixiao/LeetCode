package graph;

import java.util.*;

//课程表2 ，拓扑排序
class Solution210 {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] order = new int[numCourses];
        int[] indegree = new int[numCourses];
        Queue<Integer> queue = new LinkedList<>();

        //构建图
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            arr.add(new ArrayList<Integer>());
        }

        //计算每个结点入度，添加结点的邻居
        for(int i=0;i<prerequisites.length;i++){
            indegree[prerequisites[i][0]]++;
            arr.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }
        //将入度为0的点入队列
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                queue.offer(i);
            }
        }
        //拓扑排序
        int j=0;
        while(!queue.isEmpty()){
            int cur = queue.poll();
            order[j++] = cur;
            for(Integer neigh: arr.get(cur)){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    queue.offer(neigh);
                }
            }
        }
        for (int i=0;i<numCourses;i++){
            if(indegree[i] != 0)
                return new int[0];
        }
        return order;
    }
}

public class lc210 {
    public static void main(String[] args) {

    }
}
