package leetcode.dp;

import java.util.Stack;

class Solution5740 {
    public static int longestBeautifulSubstring(String word) {
        int n = word.length();
        if(n<5){
            return 0;
        }
        int minidx = 0;
        int maxlength = 0;
        int res = 0;

        String pattern = "aeiou";

        for(int i=1;i<n;i++){

            if(word.charAt(i)>=word.charAt(minidx) && (i-minidx+1)>maxlength){      //a e i a
                maxlength = i-minidx+1;

                if(maxlength>=5 && containsAll(word.substring(minidx,i+1),pattern)){
                    res = maxlength;
                }
            }
            if(word.charAt(i)<=word.charAt(minidx)){
                minidx = i;
//                maxlength = 0;
            }
        }
        return maxlength;
    }

    public static boolean containsAll(String s,String pattern){

        int lens = s.length(),lenp = pattern.length();
        int i=0,j=0;
        while(i<lens&&j<lenp){
            if(s.charAt(i) == pattern.charAt(j)){
              j++;
            }
            i++;
        }
        return j==lenp;
    }

    public static int longestBeautifulSubstring1(String word) {
        int n = word.length();
        if (n < 5) {
            return 0;
        }
        String s = "aeiou";
        int maxlength = 0;
        Stack<Character> stk = new Stack<>();
        stk.push(word.charAt(0));

        for(int i=1;i<n;i++){
            if(word.charAt(i)>=stk.peek()){
                stk.push(word.charAt(i));
            }else{
                maxlength = getlen(stk,maxlength);
                stk.clear();
                stk.push(word.charAt(i));
            }
        }
        maxlength = getlen(stk,maxlength);
        return maxlength;
    }

    public static int getlen(Stack<Character> stk,int maxlength){
        String s = "aeiou";
        if(stk.size()>=5 && stk.size()>=maxlength){
            int j = 0;
            for(;j<s.length();j++){
                if(!stk.contains(s.charAt(j))){
                    break;
                }
            }
            maxlength = (j==s.length())?stk.size():maxlength;
        }
        return maxlength;
    }
}

public class lc5740 {
    public static void main(String[] args) {
        String word = "a";

        int res = Solution5740.longestBeautifulSubstring1(word);

        System.out.println(res);
    }
}
