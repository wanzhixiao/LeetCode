#include<iostream>
#include<vector>
#include<stack> 
using namespace std; 

/*
接雨水：
	[4,2,0,3,2,5] 

思路1：
	单调栈，维护一个单调递减的栈，栈存储元素下标，栈底记为left ，当遍历的元素大于栈顶，则元素出栈 

思路2：
	动态规划
	能存雨水的基本思想是：一个柱子能存多少水取决于左边或右边高度的最小值减去当前的高度
	因此，使用两个数组存储左边最大高度，和右边最大高度 
*/ 
class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
		stack<int> stk;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			while(!stk.empty() && height[stk.top()] < height[i]) {
				int h = height[stk.top()];
				stk.pop();
				if (stk.empty()) {		//没有左侧的墙了 
					break;
				}
				int w = (i-stk.top()-1);
				int m = min(height[i],height[stk.top()]);
				cout << "w=" << w << " h=" << h << " m=" << m << " w * (m - h)=" << w * (m - h) <<endl;
				ans = ans + w * (m - h);
//				cout << h << " " << height[stk.top()] << " " << height[i] << " " << w << " " << (m - h) <<endl;
			}
			stk.push(i);
		}
		return ans;
    }
    
    int trap2(vector<int>& height) {
    	int n = height.size();
    	int ans = 0;
		vector<int> leftMax(n,0);
		vector<int> rightMax(n,0);
		leftMax[0] = height[0];
		rightMax[n-1] = height[n-1];
		
		for (int i = 1; i < n; i++) {
			leftMax[i] = height[i] > leftMax[i-1] ? height[i] : leftMax[i-1];
		} 
		for (int i = n-2; i >= 0; i--) {
			rightMax[i] = height[i] > rightMax[i+1] ? height[i] : rightMax[i+1];
		}
		for (int i = 1; i < n-1; i++) {
			int h = min(leftMax[i],rightMax[i]);
			ans = ans + h - height[i]; 
		}
		return ans;
    } 
};

int main() {
	vector<int> height = {4,2,0,3,2,5};
	Solution s;
	cout << s.trap2(height) << endl;
	return 0;
}
