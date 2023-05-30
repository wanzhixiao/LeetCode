#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*
���ַ����ָ�ɻ����ַ���
	˼·����̬�滮Ԥ���� + ����
		��̬�滮���s �е�ÿ���ַ����Ƿ��ǻ����ַ���
		���ݷ�ö�����е��ַ�����ϣ����ݹ�������dp������м�֦
*/
class Solution {
private:
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        if (n<=1){
            return {{s}};
        }
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j-i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        vector<string> path;
        backtrack(s, dp, path, 0);

        return ans;
    }

    void backtrack(string &s, vector<vector<bool>> &dp, vector<string> &path, int j) {
        if (j==s.length()) {
            ans.push_back(path);
            return;
        }
        for (int i = j; i < s.length(); i++) {
            if (!dp[j][i]) { // j��ʼ��i�������Ӵ��Ƿ��ǻ����ַ��� 
                continue;
            }
            string str = s.substr(j,i-j+1);	
            path.push_back(str);
            backtrack(s,dp, path, i+1);
            path.pop_back();
        }
    }
};

int main() {
	string str = "google";
	Solution s;
	vector<vector<string>> ans = s.partition(str);
	
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		} 
		cout << endl;
	}
	return 0;
}

