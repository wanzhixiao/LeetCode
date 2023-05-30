#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		priority_queue<pair<int,int>> q;			// key : nums, val: index
		int n = nums.size();
		
		for (int i = 0; i < k; i++) {
			q.push({nums[i],i});
		}
		vector<int> ans = {q.top().first};
		
		for (int i = k; i < n; i++) {
			// 加入到队列 
			q.emplace(nums[i],i);
			// 当队列中最大的数 在左边界外，去处之 
			while (q.top().second <= i-k) {
				q.pop();
			}
			// 把滑动窗口的最大数加入到结果集中 
			ans.push_back(q.top().first);
		}
		return ans;
	}
};

int main() {
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	int k = 3;
	
	Solution solu;
	vector<int> ans = solu.maxSlidingWindow(nums,k); 
	
	for (int &x : ans) {
		cout << x << " ";
	}
	cout << endl;
	
	return 0;
} 
