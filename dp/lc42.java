
package dp;


import java.util.Stack;

/*

* 画图，求下标i左右的最大值
* leftmax[i] = max(leftmax[i-1],height[i]) 1<=i<=n-1
* rightmax[i] = max(right[i+1],height[i]) 0<=i<=n-2
* res_i = min(leftmax,rightmax)-height[i]
* []
* [5,4,3,2,1]
*
*
* [1,2,3,4,5]
*
* [1,1,1,1]
* */
class Solution42 {
    public int trap(int[] height) {
        int n = height.length;
        if(n==0){
            return 0;
        }
        int[] leftMax = new int[n];
        int[] rightMax = new int[n];

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        for(int i=1; i<n;i++){
            leftMax[i] = leftMax[i-1]>height[i]?leftMax[i-1]:height[i];
            rightMax[n-i-1] = rightMax[n-i]>height[n-i-1]?rightMax[n-i]:height[n-i-1];
        }
        int res = 0;
        for(int i=0;i<n;i++){
            int minh = Math.min(leftMax[i],rightMax[i]);
            res += minh-height[i];
        }

        return res;
    }
    //官方的dp题解https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/

    //题解2，维护一个单调递减栈，栈底至栈顶依次减小
    //栈中至少有两个元素，保证mid
    public int trap2(int[] height) {
        int n = height.length;
        int res = 0;
        Stack<Integer> stk = new Stack();
        for(int i=0;i<n;i++){
            while(!stk.empty() && height[stk.peek()]<height[i]){
                int mid = height[stk.peek()];
                //去除重复的数
                while(!stk.empty() && height[stk.peek()] == mid){
                    stk.pop();
                }
                if(!stk.empty()){   //此时height[stk.peek()]>mid=height[stk.peek()]
                    //装水必须两边比中间高,根据木桶原理，取两边较矮的一边减去中间的高度即为盛水量
                    int left = stk.peek();
                    res += (i-left-1)*(Math.min(height[i],height[left])-mid);
                }
            }
            stk.push(i);
        }
        return res;
    }
}

public class lc42 {
    public static void main(String[] args) {
        int[] arr = {4,2,0,3,2,5};
        Solution42 s = new Solution42();
        int res = s.trap2(arr);
        System.out.println(res);
    }
}
