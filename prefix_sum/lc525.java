package other;


import java.util.HashMap;
import java.util.Map;

class Solution525 {
    public int findMaxLength(int[] nums) {
//        Map<Integer,Integer> map0 = new HashMap<>();
//        Map<Integer,Integer> map1 = new HashMap<>();
//        map0.put(0,0);
//        map1.put(0,0);
        int n = nums.length;
        int[] dp0 = new int[n];
        int[] dp1 = new int[n];
        if(nums[0]==0){
            dp0[0] = 1;
            dp1[0] = 0;
        }else{
            dp0[0] = 0;
            dp1[0] = 1;
        }

        int res = 0;
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                dp0[i] = dp0[i-1]+1;
                dp1[i] = dp1[i-1];
            }else{
                dp1[i] = dp1[i-1]+1;
                dp0[i] = dp0[i-1];
            }
            int minlen = dp0[i];
            if(dp0[i]>dp1[i]){
                minlen = dp1[i];
            }

            if(dp0[i]>=2*dp1[i] || dp1[i]>=2*dp0[i]){
                dp0[i] = (nums[i]==0)?1:0;
                dp1[i] = (nums[i]==1)?1:0;
                minlen = 0;
            }
            res = (minlen*2)>res?(minlen*2):res;
        }
        return res;
    }

    //再次出现相同的现象
    public int findMaxLength1(int[] nums) {
        int n = nums.length;
        int cnt0 = 0,cnt1 = 0;
        int res = 0;

        //key 为cnt1-cnt0,表示0,1数量的差值,value为差值第一次出现的位置
        Map<Integer,Integer> map = new HashMap<>();

        //长度为2的平衡数组，第0个位置设置为-1, [0,1] diff = [1,0] 对应的map = [[1,0],[0,-1]] res = [0,(1-(-1)=2]
        map.put(0,-1);

        for(int i=0;i<n;i++){
            cnt0 += (nums[i]==0)?1:0;
            cnt1 += (nums[i]==1)?1:0;
            int dif = cnt1-cnt0;
            if(map.containsKey(dif)){
                res = Math.max(res,i-map.get(dif));
            }else{
                map.put(dif,i);
            }
        }
        return res;
    }

    /**
     * 为什么从dif+1到diff是平衡的呢，即i-map.get(dif)
     * 假设dif第一次出现的位置x,第二次出现的dif位置为y,则有
     * x-dif = 0, y - dif=0
     * x = y
     * 数组的和，到x为止的0,1差为dif,到y的也为dif. 拿长度y-x 即表示消长度为x,
     * 从x+1到y的元素对dif值没有影响,长度为y-x
     */
}

public class lc525 {
    public static void main(String[] args) {
        int[] nums = {0,1,0,0,0,1,0,0,1};
        Solution525 s = new Solution525();
        int res = s.findMaxLength1(nums);
        System.out.println(res);
    }
}
