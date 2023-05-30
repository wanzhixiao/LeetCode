#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
			return a[0] < b[0];
		});
		int n = intervals.size();
		vector<vector<int>> ans;
		
		ans.push_back(intervals[0]);
		for (int i = 1; i < n; i++) {
			if (ans.back()[1] >= intervals[i][0]) {
				int r = max(ans.back()[1], intervals[i][1]);
				ans.back()[1] = r;
			} else {
				ans.push_back(intervals[i]);
			}
		} 
		return ans;
    }
};

/*
[[1,3],[2,6],[8,10],[15,18]]
	把[1,3]加入结果集 
	[1,6],[2,3]	-> [1,6]
	2 <= 3 -> 1,max(3,6)
	把[1,3]更新至[1,6] 
	[1,6] [8,10]
	6 < 8
	直接把[8,10]加入结果集
	10 < 15
	直接把[15,18]加入结果集 

最终结果	
[[1,6],[8,10],[15,18]]	
*/

int main() {
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	
	Solution solu;
	vector<vector<int>> ans = solu.merge(intervals);
	for (auto &vec : ans) {
		cout << vec[0] << " " << vec[1] << endl;
	}
	
	return 0;
}
