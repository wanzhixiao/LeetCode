'''
abcabcbb

思路：
1. 暴力法
    枚举每个子串，判断其中是否有重复字符
    for i=0 t0 n
        st = set()
        for j = i to n:
            if s[j] not in st:
                st.add(s[j])
                ans = max(j-i+1,ans)
            else:
                break
    return ans


2. 滑动窗口+哈希表
    窗口代表什么？无重复的最长子串长度
    何时移动右指针：当窗口内无重复字符时
    何时移动左指针：当l<r 并且s[r] != 0时（说明在之前已经遇到了s[r]，当前的子串中包含s[r],因此需要将左
    ）
    细节1： 判断s[r]是否在dict中
    细节2： 先cnt[s[r]]++ 在判断 l<r and cnts[s[r]] > 1
          或者先判断l<r and cnts[s[r] != 0, 再cnt[s[r]] += 1

'''

class Solution:

    # set去重 + 暴力法
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        ans = 0
        for i in range(n):
            st = set()
            for j in range(i,n):
                if s[j] not in st:
                    st.add(s[j])
                    ans = max(j-i+1,ans)
                else:
                    break
        return ans

    # 滑动窗口+哈希表
    def lengthOfLongestSubstring(self, s: str) -> int:
        cnts = defaultdict()
        l,r,n = 0, 0, len(s)
        ans = 0
        while r < n:
            while l < r and (s[r] in cnts) and cnts[s[r]] != 0:
                cnts[s[l]] -= 1
                l += 1
            if s[r] not in cnts:
                cnts[s[r]] = 1
            else:
                cnts[s[r]] += 1
            ans = max(r-l+1, ans)
            r += 1

        return ans

    def lengthOfLongestSubstring1(self, s: str) -> int:
        cnts = defaultdict()
        l,r,n = 0, 0, len(s)
        ans = 0
        while r < n:
            if s[r] not in cnts:
                cnts[s[r]] = 1
            else:
                cnts[s[r]] += 1
            while l < r and (s[r] in cnts) and cnts[s[r]] > 1:
                cnts[s[l]] -= 1
                l += 1
            ans = max(r-l+1, ans)
            r += 1
        return ans