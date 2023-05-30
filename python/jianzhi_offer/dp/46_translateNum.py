
'''
46： 把数字翻译成字符串的种数
    思想： 字符串范围为a-z表示0-25, 最多表示两位数字，只需要考虑两位的子串s[i-2,i-1]，因此可以定义子问题
    f[i] 表示以第i位数字结束的字符串的翻译种数
    f[i] = f[i-1] + f[i-2]   if s[i-2,i-1] >= '10' and s[i-2,i-1] <= 25
    f[i] = f[i-1]                               else (s[i-2,i-1] < 10 and s[i-2,i-1] > 25)
    初始化 f[0] 表示0翻译成a有一种翻译方法， 因此，f[0] = 1
    f[1] = 1, 表示将1翻译成b有一种翻译方法



'''


class Solution:
    # 记忆化搜索， 自顶向下
    def translateNum(self, num: int) -> int:
        s = str(num)
        n = len(s)
        @cache
        def dfs(i):
            # if i < 0:
            #     return 0
            if i == 0:
                return 1
            sub_str = s[i-2:i]
            if sub_str >= '10' and sub_str <= '25':
                return dfs(i-1) + dfs(i-2)
            return dfs(i-1)
        ans = dfs(n)
        return ans

    # 递推
    def translateNum(self, num: int) -> int:
        s = str(num)
        n = len(s)
        f = [0 for i in range(n+1)]
        f[0] = 1
        f[1] = 1
        for i in range(2,n+1):
            substr = s[i-2:i]
            if substr >= '10' and substr <= '25':
                f[i] = f[i-1] + f[i-2]
            else:
                f[i] = f[i-1]
        return f[n]