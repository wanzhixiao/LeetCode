


def edit_distance(str1,str2):
    len1 = len(str1)
    len2 = len(str2)

    if len1==0 or len2==0:
        return len1+len2

    dp = [[0 for _ in range(len2+1)] for _ in range(len1+1)]

    for i in range(0,len1+1):
        dp[i][0] = i
    for j in range(0,len2+1):
        dp[0][j] = j

    for i in range(1,len1+1):
        for j in range(1,len2+1):

            d = 1 if str1[i-1]!=str2[j-1] else 0

            dp[i][j] = min(dp[i-1][j-1]+d,min(1+dp[i-1][j],1+dp[i][j-1]))

    return dp[len1][len2]


ans = edit_distance("horse","ros")

print(ans)