package dp;

import java.util.*;
/*
本体要点：
要点1：
 dp+双指针
dp[i]表示以第i个数为根结点的构造种数， dp[i]=dp[j]*dp[k] * (j==k?1:2)
通过双指针在有序数组 0<=j<=k<i<n 范围内查找arr[j]*arr[k] == arr[i]

要点2：
大数防止越界
数组本身，相乘后的数都要转为long
dp[i] = dp[i]%1000000007
* */
class Solution823 {
    public int numFactoredBinaryTrees(int[] arr) {
        int n = arr.length;
        long ans = 0;
        List<Long> dp = new ArrayList<>(Collections.nCopies(n,Long.valueOf(1)));
        Arrays.sort(arr);
        long[] arr1 = new long[n];
        arr1[0] = arr[0];

        int a = 1000000007;
        for(int i=1;i<n;i++){
            arr1[i] = arr[i];
            int j=0,k=i-1;
            while(j<=k){
                long num = arr1[j]*arr1[k];
                if(num<arr1[i]){
                    j++;
                }else if(num>arr1[i]){
                    k--;
                }else{      //num == arr[k]
//                    if(k==j){
//                        dp.set(i,(dp.get(i)+dp.get(k)*dp.get(k)));  // 分解，arr[i]的组成个数
//                    }else{
//                        dp.set(i,(dp.get(i)+(dp.get(k)*dp.get(j))*2));
//                    }
                    long num_i = dp.get(i)+(dp.get(j)*dp.get(k))*(j==k?1:2);
                    dp.set(i,num_i);
                    j++;
                    k--;
                }
            }
            dp.set(i,dp.get(i)%a);
        }
        //求和
        for(int i=0;i<n;i++){
            ans = (ans+dp.get(i))%a;
        }
        return (int)ans;
    }
}

public class lc823 {
    public static void main(String[] args) {
        int[] arr = {2,4};
        Solution823 sl823 = new Solution823();
        int res = sl823.numFactoredBinaryTrees(arr);
        System.out.println(res);
    }
}
