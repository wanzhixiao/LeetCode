package leetcode.binary_search;

//题解来源
// https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/solution/chi-xiao-dou-python-wei-shi-yao-shi-er-f-24p7/
class Solution1482 {

    /*
    * 理解题意：
    * 连续的k朵花可以组成一束花，注意是连续，连续的k多花开花天数是否都小于等于 days,目标是使得days最小
    * 最少的天数，
    *
    * 解题思路
    * 使用二分查找，left=min(bloomDay[i]),表示花开的最小天数，right=max(bloomDay[i])表示花开的最大天数
    * 将right不断往左，得到更小的天数days
    * 否则，不够条件，left往右，开花的天数增加
    * 直到left==right
    * */
    public int minDays(int[] bloomDay, int m, int k) {
        //遍历序列，问题转化为，在相邻的k个数中是否能找到m个k,
        int n = bloomDay.length;
        if(m*k > n){        //如果需要的花朵数量超过数组的长度（总花朵数）
            return -1;
        }

        //low和high是天数，不是数组中的某个数字或者下标
        int left = 0; // 花开的最小天数
        int right = 0; // 花开的最大天数
        for(int i=0;i<n;i++){
            left = left<bloomDay[i]?left:bloomDay[i];
            right = right>bloomDay[i]?right:bloomDay[i];
        }

        while(left < right){            //left==right退出循环
            int mid = left + (right-left)/2;
            if(canMake(bloomDay,mid,m,k)){          //nums[mid]=right
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }

    public boolean canMake(int[] bloomDay,int days,int m,int k){
        int flowers = 0;    //连续的花朵数
        int count = 0;          //花束数量
        for(int i=0;i<bloomDay.length;i++){
            if(bloomDay[i]<=days){
                flowers++;
                if(flowers==k){    //达到连续的朵数，可以做一束花
                    flowers=0;
                    count++;
                }
            }else{              //第i多花不能开，不连续的花
                flowers = 0;
            }
            if(count>=m){
                break;
            }
        }
        return count>=m;
    }
}

public class lc1482 {
    public static void main(String[] args) {
//        int[] bloomDay = {1,10,3,10,2};
//        int m =3,k=1;
        int[] bloomDay = {7,7,7,7,12,7,7};
        int m =2,k=3;
        Solution1482 s = new Solution1482();

        int res = s.minDays(bloomDay,m,k);
        System.out.println(res);
    }
}
