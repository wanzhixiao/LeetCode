#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6

输入：height = [4,2,0,3,2,5]
输出：9
*/

int trap(vector<int>& height) {
	stack<int> stk;
	int n = height.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (!stk.empty() && height[stk.top()] < height[i]) {
			int curH = height[stk.top()];
			stk.pop();
			if (stk.empty()) {
				break;
			}
			int width = i-stk.top()-1;
			int h = min(height[stk.top()],height[i]) - curH;
			int area = width*h;
			ans += area;
		}
		stk.push(i);
	}
	return ans;
}

int main() {
	vector<int> height = {4,2,0,3,2,5};
	cout << trap(height) << endl;
	return 0;
} 
