package leetcode.dfs;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
*  [[1],[2],[3],[]]
* */
class Solution841{
    int count = 0;
    boolean[] visited = new boolean[1001];

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Arrays.fill(visited,false);
        dfs(rooms,0);
        return count==rooms.size();
    }

    public void dfs(List<List<Integer>> rooms,int v){

        visited[v] = true;
        List<Integer> sublist = rooms.get(v);
        count++;

        for(int i=0;i<sublist.size();i++){
            int j = sublist.get(i);
            if(!visited[j]){
                dfs(rooms,j);
            }
        }
        return;
    }
}

public class lc841 {
    public static void main(String[] args) {

        List<List<Integer>> list = new ArrayList<List<Integer>>();
//        list.add(new ArrayList<>(Arrays.asList(1)));
//        list.add(new ArrayList<>(Arrays.asList(2)));
//        list.add(new ArrayList<>(Arrays.asList(3)));
//        list.add(new ArrayList<>());


        list.add(new ArrayList<>(Arrays.asList(1,3)));
        list.add(new ArrayList<>(Arrays.asList(3,0,1)));
        list.add(new ArrayList<>(Arrays.asList(2)));
        list.add(new ArrayList<>(Arrays.asList(0)));
        list.add(new ArrayList<>());

        Solution841 solution = new Solution841();
        boolean result = solution.canVisitAllRooms(list);
        System.out.println(result);
    }
}
