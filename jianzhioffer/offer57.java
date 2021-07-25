package leetcode.jianzhioffer;

import java.util.Arrays;

class Solution57 {

    int[] memo = new int[100001];

    public int[][] findContinuousSequence(int target) {
        Arrays.fill(memo,-1);
        return null;
    }

    public int dfs(int cur,int target){
        if(memo[target] != -1){
            return memo[target];
        }
        int m = 0;
        for(int i=1;i<target;i++){
            if(target-i > 0)
                m = dfs(i,target-i);
        }

        return 0;
    }

}


class Solution571 {

    private int capacity = 10;

    private int[][] ans = new int[capacity][];

    public int[][] findContinuousSequence(int target) {

        int small = 1, big = 2;
        int sum;

        int t = 0, p = 0;

        // 其实取到 target / 2 就可以了
        while (small < big && small <= target / 2) {
            sum = ((small + big) * (big - small + 1)) / 2;
            if (sum < target) {
                big++;
            }
            else if (sum > target) {
                small++;
            }
            else {

                int[] subAns = new int[big - small + 1];

                for (int i = small; i <= big; i++) {
                    subAns[t++] = i;
                }

                t = 0;
                ans[p++] = subAns;

                if (p == capacity) {
                    enlargeCapacity();
                }

                small++;
            }
        }

        changeCapacity(p);

        return ans;
    }

    /**
     * 扩容
     */
    private void enlargeCapacity() {
        capacity += 10;
        ans = Arrays.copyOf(ans, capacity);
    }

    /**
     * 删除数组多余空间
     */
    private void changeCapacity(int retCapacity) {
        ans = Arrays.copyOf(ans, retCapacity);
    }
}
/*
作者：ruo-xu-5
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/kuai-man-zhi-zhen-by-ruo-xu-5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

public class offer57 {
    public static void main(String[] args) {
        int target = 9;

        Solution57 solution = new Solution57();
        int[][] arr = solution.findContinuousSequence(target);

        for(int [] ar:arr){
            for(int a:ar){
                System.out.print(a + " ");
            }
            System.out.println();
        }
    }
}
