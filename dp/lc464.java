package dp;

/*
* lc464 我能赢吗
* 待解决
* */

class Solution464 {
    int[] visited;
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        visited = new int[maxChoosableInteger+1];
        //边界条件1
        if(maxChoosableInteger>=desiredTotal) {
            return true;
        }
        //边界条件2
        if((1+maxChoosableInteger)*maxChoosableInteger/2<desiredTotal){
            return false;
        }

        return  false;
    }

    public boolean dfs(int state, int cursum, int maxChoosableInteger, int desiredTotal){

        return false;
    }
}

public class lc464 {
    public static void main(String[] args) {
        int maxChoosableInteger=10,desiredTotal=11;
        Solution464 solu = new Solution464();

        boolean res = solu.canIWin(maxChoosableInteger,desiredTotal);
        System.out.println(res);

    }
}
