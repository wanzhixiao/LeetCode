#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    	vector<vector<int>> ans;
    	unordered_map<int, pair<int,int>> mp;		// key�� ʮ�������� value :�������±귶Χ [left,right] 
    	
//       if (auto i = s.find('0'); i != string::npos)
//            m[0] = {i, i}; // ��������Ϳ���ֱ������ '0' �ˣ�Ч�ʸ���

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
Ѱ���Ӵ��� ��queries�������

101101
query1 = [0,5]
101-> 5 ^ 0 = 5
query2 = [1,2]
11 -> 3 ^ 1 = 2

1. ˼·1
����ÿ��query, ö��ÿ���Ӵ�s1����s��ʮ���� a ^ query[0] == query[1]�� Ϊÿ��query�ҵ���̵�s1
ʱ�临�Ӷȣ�O(len(query)) * O(len(s)) * O(len(s))

2. ˼·2
    ����ת���� 
        val^first = second
        val^first^first = second^first, ���� first^first = 0, val ^ 0 = val
        val = second ^ first
    step 1: Ԥ�����ַ����� ��ÿ���Ӵ������ʮ���ƴ浽map, key��ʮ���ƣ�value���Ӵ�����ʼ����ֹ�±�
    step 2: ����querys, ���ÿ��querys��Ӧ��left, right
    ʱ�临�Ӷȣ� O(len(s)) * O(len(s)), �ռ临�Ӷ� O(n^2)
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
