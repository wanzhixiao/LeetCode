#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
给定一个n生成，n对有效的括号
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

n = 3 
 
*/

class Solution {
private: 
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
    	if (n == 0) {
    		return ans;
		}
		string path = "";
		dfs(path,n,n);
		
        return ans;
    }

    void dfs(string s, int left, int right) {
		if (left == 0 && right == 0) {
			ans.push_back(s);
			return;
		}
		if (left > right) {
			return;
		}
		if (left > 0) {
			dfs(s+'(',left-1,right);
		}
		if (right > 0) {
			dfs(s+')',left, right-1);
		}
    }
};

int main() {
	Solution solu;
	int n = 2;
	vector<string> vec = solu.generateParenthesis(n);

	for (string &s : vec) {
		cout << s << " ";
		cout << endl;
	}
	
	return 0;
} 
