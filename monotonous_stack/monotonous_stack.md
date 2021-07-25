##单调栈  
739：每日温度：https://leetcode-cn.com/problems/daily-temperatures/    
496：下一个最大元素：https://leetcode-cn.com/problems/next-greater-element-i/    
1856：子数组最小乘积的最大值：https://leetcode-cn.com/problems/maximum-subarray-min-product/solution/python-qian-zhui-he-dan-diao-zhan-qing-x-gow8/      
84：柱状图中的最大矩形：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/    

相关知识    
单调递增栈，栈底到栈顶元素依次增大。常用于求下一个更大的元素，例如 4,1,3,2,4,5  
```java
int[] right = new int[n];
for(int i=0;i<n;i++){
    while(!stk.empty() && nums[stk.peek()]<nums[i]){
        right[stk.peek()] = i;          //right记录下一个更大元素的下标  
        stk.pop(); 
    }
    stk.push(i);
}
```


单调递减栈，栈底到栈顶元素依次递减。常用于求下一个更小的元素，例如 3,1,2,3  

```java
int[] left = new int[n];
Arrays.fill(left,-1)
for(int i=0;i<n;i++){
    while(!stk.empty() && nums[stk.peek()]<nums[i]){
        left[i] = stk.peek();          //left[i]记录前一个更小元素的下标  
        stk.pop(); 
    }
    stk.push(i);
}
```
