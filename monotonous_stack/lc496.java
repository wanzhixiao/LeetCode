package leetcode.monotonous_stack;

import java.util.HashMap;
import java.util.Stack;


//下一个更大元素
//维护一个单调递减栈，栈底到栈顶元素依次减小
//对于第二个数组，将第0个元素入栈，继续遍历第二个数组
//如果第i个元素比栈顶大，则出栈，用hashmap保存 (栈顶元素，nums2[i]),nums2[i]即为栈顶元素的下一个更大元素
//否则 stk.top()>=nums2[i]，nums2[i]入栈，用于等待寻找下一个更大元素

class Solution496 {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        HashMap<Integer,Integer> map = new HashMap();
        Stack<Integer> stk = new Stack();
        int[] res = new int[nums1.length];

        stk.push(nums2[0]);

        for(int i=1;i<nums2.length;i++){
            while(!stk.empty() && stk.peek()<nums2[i]){     //如果栈顶元素比nums2[i]小，则出栈，栈顶元素的下一个更大元素为nums2[i]
                map.put(stk.peek(),nums2[i]);
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        for(int i=0;i<nums1.length;i++){
            if(map.get(nums1[i]) == null){
                res[i] = -1;
            }else{
                res[i] = map.get(nums1[i]);
            }
//            res[i] = map.getOrDefault(nums1[i],-1);如果没有则返回-1
        }
        return res;
    }
}

public class lc496 {
    public static void main(String[] args) {
//        int[] nums1 = {4,1,2};
//        int[] nums2 = {1,3,4,2};
        int[] nums1 = {1};
        int[] nums2 = {1,2};

        Solution496 s = new Solution496();

        int[] res = s.nextGreaterElement(nums1,nums2);

        for(int a:res){
            System.out.println(a);
        }

    }
}
