## 二分查找的变种

当待查询的数组中有重复值的时候，要求返回匹配数据的最小或最大下标，找出第一个大于key的元素  

变种原理与二分查找类似，需要注意边界条件

几种变体：  
1.数组中存在重复元素时，返回第一个相等的值,返回最后一个相等的值，leetcode34   
2.upper_bound,返回第一个大于等于key的值 ,leetcode 5171  
3.lower_bound,返回第一个小于等于key的值  
