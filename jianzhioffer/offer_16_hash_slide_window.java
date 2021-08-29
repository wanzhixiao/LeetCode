package jianzhioffer;

import java.util.HashMap;
//min_len_substring,最长无重复子串
//哈希+滑动窗口
class Solution16 {

    //String s = "tmmzuxt";错误
    public int lengthOfLongestSubstring(String s) {
        int left = 0, right = 0,pre = 0;
        int n = s.length();
        int ans = 0;
        HashMap<Character,Integer> map = new HashMap<>();

        while(right < n){
            char ch = s.charAt(right);
            if(!map.containsKey(ch)){
                ans = (right-left+1)>ans?(right-left+1):ans;
            }else {
                pre = left;
                left = map.get(ch) + 1;
                for(int i=pre;i<left;i++){
                    if(map.containsKey(s.charAt(i))){
                        map.remove(s.charAt(i));
                    }
                }
            }
            map.put(ch,right);
            right++;
        }
        return ans;
    }

    public int lengthOfLongestSubstring2(String s) {
        int left = 0, right = 0,pre = 0;
        int n = s.length();
        int ans = 0;
        HashMap<Character,Integer> map = new HashMap<>();

        while(right < n){
            char ch = s.charAt(right);
            if(map.containsKey(ch) && map.get(ch)>=left){//tmmzuxt left = 2,  不满足 map.get('t') = 0 > 2='m'
                left = map.get(ch) + 1;
            }
            map.put(ch,right);
            ans = (right-left+1)>ans?(right-left+1):ans;
            right++;
        }
        return ans;
    }
}

public class offer_16_hash_slide_window {
    public static void main(String[] args) {
        String s = "tmmzuxt";
        Solution16 solu = new Solution16();

        int res = solu.lengthOfLongestSubstring2(s);
        System.out.println(res);
    }
}
