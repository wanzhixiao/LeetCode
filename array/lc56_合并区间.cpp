#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

/*
合并区间
 [1,3],[2,6],[8,10],[15,18]
 
思路：
	用一个数组ans保存结果，
	将 ans的最后一个元素与当前要合并的区间进行合并，合并规则
	ans.back()[0] >= intervals[i][1]; 比较右端点
	
	合并[1,3]和[2,6];
	3 >= 2;
	l = 1;  r = max(3,6)  合并之后  [1,6] 
*/ 

class Solution {
public:
	static bool cmp(const vector<int>& a,const vector<int>& b){
	    return a.back()<b.back();
	}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(),intervals.end(),cmp);
		
		int n = intervals.size();
		ans.push_back(intervals[0]);
		
		for (int i = 1; i < n; i++) {
			if (ans.back()[1] >= intervals[i][0]) {
				int r = ans.back()[1] > intervals[i][1] ? ans.back()[1] : intervals[i][1];
				ans.back()[1] = r;
			} else {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
    }
};

int main() {
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	Solution solu;
	vector<vector<int>> ans = solu.merge(intervals);
	for(vector<int> &vec : ans) {
		for(int &x : vec) {
			cout << x << " ";
		}
		cout <<endl;
	}
	return 0;
}
