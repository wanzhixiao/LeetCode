#include<bits/stdc++.h>
#define max(a,b) a > b ? a : b
using namespace std;
 
class Solution {
private:
    int ans = 0;
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<vector<int>> cnt(n,vector<int>(26,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0,m = arr[i].size(); j < m; j++) {
                ++cnt[i][arr[i][j]-'a'];
            }
        }
        vector<vector<bool>> same(n, vector<bool>(n,false));
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool flag = false;
                for (int k = 0, m = arr[j].size(); k < m; k++) {
                    if (cnt[i][arr[j][k]-'a'] > 0 && cnt[j][arr[j][k]-'a'] > 0) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    same[i][j] = true;
                }
            }
        }
        vector<bool> used(n,false);
        vector<int> path;
        dfs(arr,used, path, same, 0);

        return ans;
    }
    void dfs(vector<string> &arr, vector<bool> &used, vector<int> &path, vector<vector<bool>>& same, int cur){
        int n = arr.size();
        
        // cout << path.size() << endl;
        string s = "";
		for (int t : path) {
			s += arr[t];
		}
		
		ans = max(ans,s.size());
		
        if (cur == n) {
            return;
        }
        
        for (int i = cur; i < n; i++) {
        	
        	bool flag = false; 
            // 两个单词包含相同的字符
            for (int j : path) {
            	if (j != i && same[i][j]) {
//	            	cout  << arr[j] <<" 000 "<< arr[i] << endl;
	               	flag = true;
	               	break;
            	}
			}

//            cout  << arr[cur] <<" 111 "<< arr[i] << " cur =  " << cur << " i = " << i << " size = " << path.size()<< endl;
            // 单词i没有被使用
            if (!used[i] && !flag) {
//                used[i] = true;
				path.push_back(i);
//				cout << cur << " = " << i << " = " << path.size() << endl;
                dfs(arr,used, path, same, i+1);
                path.pop_back();
                used[i] = false;
            }
        }
        return;
    }
};

int main() {
	vector<string> arr = {"zog","nvwsuikgndmfexxgjtkb","nxko"};
	Solution s;
	int ans = s.maxLength(arr);
	cout << ans << endl;
	
	return 0;
} 
