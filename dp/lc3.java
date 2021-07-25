package dp;

import java.util.*;


class Solution3 {
    public int lengthOfLongestSubstring(String s) {
        if(s != null && s.equals("")){
            return 0;
        }
        Queue<Character> queue = new LinkedList<>();
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            if(!queue.contains(s.charAt(i))){

            }else{
                maxlen = Math.max(queue.size(),maxlen);
                while(!queue.isEmpty() && queue.contains(s.charAt(i))){
                    queue.poll();
                }
            }
            queue.offer(s.charAt(i));
        }
        maxlen = Math.max(queue.size(),maxlen);
        return maxlen;
    }

    public int lengthOfLongestSubstring1(String s) {
        //滑动窗口 + hashset
        //LinkedHashSet就支持插入顺序遍历
        int n = s.length();
        int ans = 0;
//        Set<Character> set = new LinkedHashSet<>();
        Set<Character> set = new HashSet<>();
        int i=0,j=0;
        for(;i<n&&j<n;)
        {
            if(!set.contains(s.charAt(j)))
            {
                set.add(s.charAt(j++));
                ans = Math.max(ans,j-i);
            }
            else
            {
                set.remove(s.charAt(i++));      //这个地方不严谨，哈希set不能保证有序，可换成LinkedHashSet
            }
        }
        return ans;
    }
    //关于HashSet的讨论：https://www.zhihu.com/question/28414001
}

public class lc3 {
    public static void main(String[] args) {
        String s = " akd";
        Solution3 solu3 = new Solution3();

        int out = solu3.lengthOfLongestSubstring1(s);
        System.out.println(out);
//        Random rand=new Random(47);
//        Set<Integer> intset=new LinkedHashSet<Integer>();
//        for (int i=0;i<10000;i++){
//            intset.add(rand.nextInt(30));
//        }
//        Iterator<Integer> iterator=intset.iterator();
//        while (iterator.hasNext()){
//        System.out.print(iterator.next()+" ");
    }
}

/*
Python题解:, 滑动窗口
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        strlen = len(s)
        if(strlen==0):
            return 0
        maxlen = 1
        # for i in range(strlen):
        #     j = i+1
        #     curlen = 1
        #     while(j<=strlen-1 and s[i] != s[j]):
        #         curlen += 1
        #         j += 1


#         hashmap = {}
#         for i in range(strlen):

#             if s[i] not in dic.keys():
#                 hashmap[s[i]] = i
#             j = i+1
#             while(j<strlen):
#                 if(s[j] in hashmap):
#                     break
#                 else:
#                     hashmap[s[j]] = j
#                     j += 1
#             j -= 1
#             curlen = hashmap[s[j]] - hashmap[s[i]]
#             maxlen = curlen if curlen>maxlen else maxlen

        dic = {}
        start = 0
        res = 0
        for i in range(len(s)):
            cur = s[i]
            if cur not in dic.keys():
                dic[cur] = i
            else:
                if(dic[cur] + 1>start):
                    start = dic[cur]+1
                dic[cur] = i
            if(i-start+1 > res):
                res = i-start+1

        return res
* */