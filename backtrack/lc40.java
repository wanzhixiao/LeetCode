package backtrack;
import java.util.*;

public class lc40 {
    private static List<List<Integer>> res;
    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        res = new ArrayList<>();
        List<Integer> arr = new ArrayList<>();
        backtrak(candidates, arr, target,0);
        return res;
    }

    public static void backtrak(int[] condidates,List<Integer> arr,int target,int i){
        if(target==0){
            res.add(new ArrayList<>(arr));
        }
        for(int j=i;j<condidates.length;j++){
            if(target-condidates[j]<0){
                break;
            }
            //去除重复的分支
            if(j>i && condidates[j]==condidates[j-1]){
                continue;
            }
            arr.add(condidates[j]);
            backtrak(condidates,arr,target-condidates[j],j+1);
            arr.remove(arr.size()-1);
        }
    }


    public static void main(String[] args) {
        int[] candidates = {2,5,2,1,2};
        int target = 5;
//        int[] candidates = {2,3,5,7};
////        int target = 5;
        List<List<Integer>> res = combinationSum2(candidates,target);
        System.out.println(res);
    }

}
