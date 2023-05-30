#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n,0);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                //第i-1个为左括号
                if (s[i-1] == '(') {
                    //i>=2, 是则要加上dp[i-2]

                    //子问题为 dp[i-2]
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    //s[i-1] == ')', 要看s[i-1-dp[i-1]] == '('  
                    //若是， dp[i] = dp[i-1] + 2; 
                    //还要考虑dp[i-1-dp[i-1]-1]这段的子问题

                    //子问题为dp[i-1dp[i-1]-1]
                    dp[i] = dp[i-1] + ((i-dp[i-1]-2 >= 0) ? dp[i-dp[i-1]-2]:0) +2;
                }
                // if (s[i-1] == '(') {
                //     dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                // } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                //     dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                // }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

/*
    dp[i]表示以i为结尾的位置最长有效括号的长度
    
    当s[i] == ')' , 看s[i-1]能否与s[i]配对， s[i-1] == '(', 则配对成功，考虑子问题dp[i-2]
                    若s[i-1] == ')', 此时还要看更前面的s[i-1-dp[i-1]] 是否 == '(' ? , 若是，s[i-1]匹配成功，
                    继续考虑 dp[i-1-dp[i-1]-1]的子问题
            s[i] == ')'  && s[i-1] == '(' , dp[i-2]
            s[i] == ')' && s[i-1] == ')',看s[i-1]是否配对成功，dp[i-1-dp[i-1]-1]
*/

int main() {
	string s = "()(())";
	Solution solu;
	cout << solu.longestValidParentheses(s) << endl;
	return 0;
} 
