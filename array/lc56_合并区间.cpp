#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

/*
�ϲ�����
 [1,3],[2,6],[8,10],[15,18]
 
˼·��
	��һ������ans��������
	�� ans�����һ��Ԫ���뵱ǰҪ�ϲ���������кϲ����ϲ�����
	ans.back()[0] >= intervals[i][1]; �Ƚ��Ҷ˵�
	
	�ϲ�[1,3]��[2,6];
	3 >= 2;
	l = 1;  r = max(3,6)  �ϲ�֮��  [1,6] 
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
