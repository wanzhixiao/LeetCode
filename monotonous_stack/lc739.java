package leetcode.monotonous_stack;


//下一个高于前温度更高需要等多少天
//维护一个单调递减栈，栈底到栈顶的元素依次减小
//当 当前遍历的元素小于栈顶元素，表明之前的温度都比当前的温度高，
//如果当前元素比栈顶元素大，则出栈，直到栈顶元素大于当前元素，在出栈的过程计算栈顶元素与遍历元素的差值，即为下一个更大元素的距离

import java.util.Stack;

class Solution739 {
    public int[] dailyTemperatures(int[] temperatures) {

        Stack<Integer> stk = new Stack<>();
        int[] res = new int[temperatures.length];
        stk.push(0);

        for (int i = 1; i < temperatures.length; i++) {
            while (!stk.empty() && temperatures[stk.peek()] < temperatures[i]) {
                res[stk.peek()] = i - stk.peek();
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            res[stk.peek()] = 0;
            stk.pop();
        }
        return res;
    }

    //题解2来源：https://leetcode-cn.com/problems/daily-temperatures/solution/jie-ti-si-lu-by-pulsaryu/
    //思路，逆序遍历，j += result[j]
    //75，71，69，72，76，73 对应 ？，2，2，1，0，0
    //计算75时，往后遍历，因为71已经计算好，可以在71的基础上直接跳到72，再跳到76,
    //计算得出75的下一个更大元素距离为 4

    public int[] dailyTemperatures2(int[] T) {
        int length = T.length;
        int[] result = new int[length];

        //从右向左遍历
        for (int i = length - 2; i >= 0; i--) {
            // j+= result[j]是利用已经有的结果进行跳跃
            for (int j = i + 1; j < length; j += result[j]) {
                if (T[j] > T[i]) {
                    result[i] = j - i;
                    break;
                } else if (result[j] == 0) { //遇到0表示后面不会有更大的值，那当然当前值就应该也为0
                    result[i] = 0;
                    break;
                }
            }
        }
        return result;
    }
}


public class lc739 {
    public static void main(String[] args) {
        int[] temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
        Solution739 s = new Solution739();
        int[] res = s.dailyTemperatures(temperatures);

        for(int a:res){
            System.out.print(a+" ");
        }
        System.out.println();
    }
}
