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
                //��i-1��Ϊ������
                if (s[i-1] == '(') {
                    //i>=2, ����Ҫ����dp[i-2]

                    //������Ϊ dp[i-2]
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    //s[i-1] == ')', Ҫ��s[i-1-dp[i-1]] == '('  
                    //���ǣ� dp[i] = dp[i-1] + 2; 
                    //��Ҫ����dp[i-1-dp[i-1]-1]��ε�������

                    //������Ϊdp[i-1dp[i-1]-1]
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
    dp[i]��ʾ��iΪ��β��λ�����Ч���ŵĳ���
    
    ��s[i] == ')' , ��s[i-1]�ܷ���s[i]��ԣ� s[i-1] == '(', ����Գɹ�������������dp[i-2]
                    ��s[i-1] == ')', ��ʱ��Ҫ����ǰ���s[i-1-dp[i-1]] �Ƿ� == '(' ? , ���ǣ�s[i-1]ƥ��ɹ���
                    �������� dp[i-1-dp[i-1]-1]��������
            s[i] == ')'  && s[i-1] == '(' , dp[i-2]
            s[i] == ')' && s[i-1] == ')',��s[i-1]�Ƿ���Գɹ���dp[i-1-dp[i-1]-1]
*/

int main() {
	string s = "()(())";
	Solution solu;
	cout << solu.longestValidParentheses(s) << endl;
	return 0;
} 
