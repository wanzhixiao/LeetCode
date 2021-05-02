package leetcode;

/*贪心算法之加油站*/


class Solution134 {
    public int canCompleteCircuit1(int[] gas, int[] cost) {
        int n = cost.length;
        int maxgas = 0, idx = 0;
        for (int i = 0; i < n; i++) {
//            if ((gas[i] - cost[i]) > maxgas) {
                if((gas[i]-cost[i])+gas[(i+1)%n]-cost[(i+1)%n]>0){
//                    if()
//                    maxgas = gas[i] - cost[i];
                    idx = i;
                }
//            }
        }
        //从3号站开始走
        int cur = idx;
        System.out.println(cur);
        int left = gas[cur];
        while((cur+1)!=idx){
            left = left - cost[cur] + gas[(cur+1)%n];
            cur = (cur+1)%n;
            if(left<cost[cur]){
                return -1;
            }
        }
        return idx;
    }

/*
首先判断总gas能不能大于等于总cost，如果总gas不够，一切都白搭对吧（总（gas- cost）不用单独去计算，和找最低点时一起计算即可，只遍历一次）；

再就是找总（gas-cost）的最低点，不管正负（当然如果最低点都是正的话那肯定能跑完了）；

think1： 找到最低点后，如果有解，那么解就是最低点的下一个点，因为总（gas-cost）是大于等于0的，所以前面损失的gas我从最低点下一个点开始都会拿回来！
（此处@小马哥！），别管后面的趋势是先加后减还是先减后加，最终结果我是能填平前面的坑的。


画柱状图和两条曲线

* */

    public int canCompleteCircuit(int[] gas, int[] cost){

        int n = gas.length;
        int run = 0,total=0;
        int start = 0;
        for(int i=0; i<n; i++){
            run += gas[i] - cost[i];
            total += gas[i] - cost[i];  // 前半部分最后一个到不了的站点缺少的油就是后半部分剩下的油来补充的，如果后半部分剩下的油 >= 前半部分缺少的油

            if(run<0) {     //车从i站不能开到i+1，将第i+1站，则以下一个站为起点
                start = i + 1;
                run = 0;
            }
        }
        //B剩余的油>=A缺少的总油。必然可以推出，B剩余的油>=A站点的每个子站点缺少的油。
        return total<0?-1:start;        //总的gas<总的cost，开不到
    }
}

public class lc134 {

    public static void main(String[] args) {
//        int []gas  = {1,2,3,4,5};
//        int []cost = {3,4,5,1,2};
//        int []gas  = {2,3,4};
//        int []cost = {3,4,3};
//
        int []gas  = {5,8,2,8};
        int []cost = {6,5,6,6};

        Solution134 s = new Solution134();
        System.out.println(s.canCompleteCircuit(gas,cost));
    }
}
