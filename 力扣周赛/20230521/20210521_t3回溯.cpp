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
        // �ж� i�Ƿ����square��һ��ʮ���������ָ�
        
        // ��ν�square�ָ��Ӵ������Էָ�������������ַ���
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
			path.push_back(str); //����һ���зֵ����dfs 
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
