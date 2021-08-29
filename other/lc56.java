package other;

import java.util.*;
//合并区间
public class lc56 {
    //排序
    public static int[][] merge(int[][] intervals) {
        List<int[]> arr = new ArrayList<int[]>();
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0] != o2[0]){
                    return o1[0] - o2[0];
                }
                return o1[1] - o2[1];
            }
        });

        arr.add(intervals[0]);
        for(int i=1;i<intervals.length;i++){
            int[] pre = arr.get(arr.size()-1);
            int[] cur = intervals[i];
            if(cur[0]>=pre[0]&&cur[1]<=pre[1]){
                continue;
            }
            if(cur[0]<=pre[1] && cur[1]>=pre[1]){
                arr.remove(arr.size()-1);
                arr.add(new int[]{pre[0],cur[1]});
            }else{
                arr.add(cur);
            }
        }
        return arr.toArray(new int[arr.size()][]);
    }
    public static void main(String[] args) {
        int[][] arr = {{1,4},{1,4}};

        int[][] res = merge(arr);
        for(int i=0;i<res.length;i++){
            System.out.println("j[0]="+res[i][0]+" j[1]="+res[i][1]);
        }
    }
}
