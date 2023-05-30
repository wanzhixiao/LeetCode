#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i)) {
                ans += i*i;
            }
        }
        return ans;
    }
    bool check(int i) {
        int squre = i*i;
        // 判断 i是否等于square的一种十进制整数分割
        
        // 如何将square分割子串？可以分割成若干连续子字符串
        string s = to_string(squre);
        string num = to_string(i);
        vector<string> path;
        bool res = dfs(s, path, 0, num);
        return res;
    }
    
    bool dfs(string s, vector<string> &path, int i, string num) {
        if (i == s.size()) {
        	int tmp = 0;
        	for (string x : path) {
        		tmp += stoi(x);
			}
			if (tmp == stoi(num)) {
				return true;
			}
			return false;
        }
        bool res = false;
		for (int j = i; j < s.size(); j++) {
			string str = s.substr(i,j-i+1);
			path.push_back(str); //从下一个切分点继续dfs 
			res = res || dfs(s,path,j+1,num);
			if (res) {
				return res;
			}
			path.pop_back();
		}
		return res;
    }
};


int main() {
	Solution solu;
	int n = 37;
	int ans = solu.punishmentNumber(n); 
	cout << ans << endl;
	return 0;
}
