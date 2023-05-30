#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    	vector<vector<int>> ans;
    	unordered_map<int, pair<int,int>> mp;		// key： 十进制数， value :二进制下标范围 [left,right] 
    	
//       if (auto i = s.find('0'); i != string::npos)
//            m[0] = {i, i}; // 这样下面就可以直接跳过 '0' 了，效率更高

    	for (int i = 0, n = s.size(); i < n; i++) {
    		if (s[i] == '0'){
    			continue;
			}
			for (int j = i, x = 0; j < min(i+30, n); j++) {
//				x = (x << 1) | (s[j] & 1);
				 x = x*2 + s[j] % 2;
				if (!mp.count(x)) {
					mp[x] = {i,j};
				}
			}
		}
		
		for (int i = 0, n = queries.size(); i < n; i++) {
			auto it = mp.find(queries[i][0] ^ queries[i][1]);
			if (it == mp.end()) {
				ans.push_back({-1,-1});
			} else {
				ans.push_back({it->second.first, it->second.second});
			}
		} 
		return ans;
    }
};

/*
寻找子串， 与queries进行异或

101101
query1 = [0,5]
101-> 5 ^ 0 = 5
query2 = [1,2]
11 -> 3 ^ 1 = 2

1. 思路1
对于每个query, 枚举每个子串s1，看s的十进制 a ^ query[0] == query[1]， 为每个query找到最短的s1
时间复杂度，O(len(query)) * O(len(s)) * O(len(s))

2. 思路2
    问题转化： 
        val^first = second
        val^first^first = second^first, 由于 first^first = 0, val ^ 0 = val
        val = second ^ first
    step 1: 预处理字符串， 将每个子串代表的十进制存到map, key是十进制，value是子串的起始和终止下标
    step 2: 遍历querys, 求得每个querys对应的left, right
    时间复杂度： O(len(s)) * O(len(s)), 空间复杂度 O(n^2)
*/

int main() {
	string s = "101101";
	vector<vector<int>> queries = {{0,5},{1,2}};
	
	Solution solu;
	vector<vector<int>> ans = solu.substringXorQueries(s,queries);
	
	for (auto &vec : ans) {
		for (auto &x : vec) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
