package leetcode.binary_search;

/*供暖器
* 理解题意，覆盖所有房屋的最小加热半径，就是房屋最近的加热半径，对这个半径取极小
* 然后对整体取最大
*
* */

import java.util.Arrays;

class Solution {

    //暴力解法
    public int findRadius1(int[] houses, int[] heaters) {
        int res = -1;
        for(int i=0;i<houses.length;i++){       //遍历每个房屋
            int resi = Integer.MAX_VALUE;
            for(int j=0;j<heaters.length;j++){      //找出离房屋i最近的供暖器
                resi = Math.min(Math.abs(heaters[j]-houses[i]),resi);
            }
            res = Math.max(res,resi);           //因为要覆盖所有的供暖器，所以结果为最长的半径
        }
        return res;
    }

    //二分查找
    //二分查找的前提是有序，先对数组进行排序，遍历每个房屋i，查找离房屋i最近的供暖器，包括左边和右边的的最近供暖器
    /*https://leetcode-cn.com/problems/heaters/solution/man-hua-tu-jie-er-fen-cha-zhao-gong-nuan-qi-by-iva/
    二分查找的目的是找到比house大，但又离house最近的heater。找到heater后，
    当前house需要的最小半径=min(当前heater离house的距离，上一个heater离house的距离)。 但是查找的时候可能存在两种极端：
    *right==0
    right==1
     */

    public int findRadius2(int[] houses, int[] heaters) {
        //升序排序
        Arrays.sort(houses);
        Arrays.sort(heaters);

        int res = 0;
        for(int i=0;i<houses.length;i++){

            int left=0,right=heaters.length-1;

            //从左边找近供暖器,查找的target为house[i]
            while(left<right){
                int mid = left+right>>1;
                if(heaters[mid]<houses[i]){
                    left = mid+1;
                }else{
                    right = mid;
                }
            }
            int dist1 = (right==0)? Integer.MAX_VALUE:Math.abs(houses[i]-heaters[right-1]);     //right-1是上一个heater
            int dist2 = (right==heaters.length)?Integer.MAX_VALUE:Math.abs(houses[i]-heaters[right]); //right是当前heater

            //对于house[i]取最小，对于所有的house取最大
            res = Math.max(res,Math.min(dist1,dist2));
        }

        return res;
    }


}

public class lc475 {
    public static void main(String[] args) {
//        int[] houses = {1,2,3,4};
//        int[] heaters = {2};
        int[] houses = {1,5};
        int[] heaters = {10};

        Solution s = new Solution();
        int res = s.findRadius2(houses,heaters);
        System.out.println(res);
    }
}
