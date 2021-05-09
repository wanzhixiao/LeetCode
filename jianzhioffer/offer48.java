package leetcode.jianzhioffer;


import java.util.HashMap;
import java.util.Map;

/*
* 最长不重复子串
* 输入：abcabcbb，输出：3
* 输入：bbbbb，输出：1
* 输入：pwwkew，输出：3
* 输入；dvdf，输出：3
* */

class Solution48 {
    //解法1：哈希表+双指针
    //定义快慢两个指针i和j,j往右遍历，遍历过程把s[j]及位置j存入hashmap，hashmap统计字符 s[j]最后一次出现的索引
    //hashmap存在s[j],则移动慢（左）指针，左指针的位置为max(i,idx+1),离j更近的无重复的位置
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> hashtable = new HashMap<>();
        int res = 0;
        int i=0,j=0;
        while(j<s.length()){
            Integer idx = hashtable.get(s.charAt(j));
            if(idx != null){
                i = Math.max(i,idx+1);                          //abcacab,  当i指向a,j指向b,此时idx+1<i,中间还是会包含重复的c
            }
            res = Math.max(res,j-i+1);
            hashtable.put(s.charAt(j),j);       //更新s[j]的位置
            j++;
        }
        return res;
    }
}

public class offer48 {
    public static void main(String[] args) {
        String str = "abcabcbb";
        Solution48 s = new Solution48();
        int res = s.lengthOfLongestSubstring(str);
        System.out.println(res);
    }
}
