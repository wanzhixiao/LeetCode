package backtrack;

import java.util.*;


public class lc39 {
    private static List<List<Integer>> res;
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {

        res = new ArrayList<>();
        List<Integer> arr = new ArrayList<>();
        backtrack(candidates,arr,target,0);

        return res;
    }

    private static void backtrack(int[] condicates,List<Integer> arr,int target,int i){
        if(target<0){
            return;
        }
        if(target==0){
            res.add(new ArrayList<>(arr));
            return;
        }
        for(int j=i;j<condicates.length;j++){
            arr.add(condicates[j]);         //递归树上的变量，回溯的容器是一个全局变量，用于做选择
            backtrack(condicates,arr,target-condicates[j],j);       //target-condicates[j]是下一个尝试的变量
            arr.remove(arr.size()-1); //返回上一步
        }
    }

    public static void main(String[] args) {
        int[] candidates = {2,3,6,7};
        int target = 7;
        List<List<Integer>> res = combinationSum(candidates,target);
        System.out.println(res);

    }
}
