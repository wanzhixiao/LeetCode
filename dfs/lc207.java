
package dfs;


import java.util.ArrayList;
import java.util.List;


/*
*       0  -   3
*     /  \  \  |
*    1 -  2   4
* */

class Solution207 {
    private List<Integer>[] g_list;

    //思路,用stack保存哪些结点在栈上,如果同时在栈上且被访问过，则有环

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        boolean[] visited = new boolean[numCourses];
        boolean[] stack = new boolean[numCourses];
        g_list = new ArrayList[numCourses];
        //构建邻接表
        for(int i=0;i<numCourses;i++){
            g_list[i] = new ArrayList<>();
        }
        for(int[] z : prerequisites){
            g_list[z[0]].add(z[1]);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,stack)){
                    return false;
                }
            }
        }
        return true;
    }
    private boolean dfs(int v,boolean[] visited,boolean[] stack){
        visited[v] = true;
        stack[v] = true;
        for(int i : g_list[v]){
            if(visited[i] && stack[i]){
                return true;
            }
            if(visited[i]) {
                continue;
            }
            if(dfs(i,visited,stack)){
                return true;
            }
        }
        stack[v] = false;
        return false;
    }
}

public class lc207 {
    public static void main(String[] args) {
        int numCourses = 2;
        int[][] prerequisites = new int[][]{{1,0}};
        Solution207 s = new Solution207();
        boolean res = s.canFinish(numCourses,prerequisites);
        System.out.println(res);
    }
}
