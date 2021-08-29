package backtrack;
import java.util.*;

public class lc216 {
    private static List<List<Integer>> res;
    public static List<List<Integer>> combinationSum3(int k, int n) {
        res = new ArrayList<>();
        if((9+1)*9/2<n){
            return res;
        }

        List<Integer> list = new ArrayList<>();
        backtrack(n,0,k,1,list);
        return res;
    }

    public static void backtrack(int n,int sum,int k,int i,List<Integer> list){
        if (sum > n) { // 剪枝操作
            return;
        }
        if(k==list.size()){
            if(sum==n)
                res.add(new ArrayList<>(list));
            return;     //如果选择了k个数字但总和不为n直接返回
        }

        for(int j=i;j<=9;j++){   //限定下一层的结点取值
            //做决定
            sum+=j;
            list.add(j);
            //尝试
            backtrack(n,sum,k,j+1,list);
            //撤销决定
            sum-=j;
            list.remove(list.size()-1);
        }
    }

    public static void main(String[] args) {
        int k=3;
        int n=7;
        List<List<Integer>> res = combinationSum3(k,n);
        System.out.println(res);
    }
}
