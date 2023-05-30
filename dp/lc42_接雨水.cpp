#include<iostream>
#include<vector>
#include<stack> 
using namespace std; 

/*
����ˮ��
	[4,2,0,3,2,5] 

˼·1��
	����ջ��ά��һ�������ݼ���ջ��ջ�洢Ԫ���±꣬ջ�׼�Ϊleft ����������Ԫ�ش���ջ������Ԫ�س�ջ 

˼·2��
	��̬�滮
	�ܴ���ˮ�Ļ���˼���ǣ�һ�������ܴ����ˮȡ������߻��ұ߸߶ȵ���Сֵ��ȥ��ǰ�ĸ߶�
	��ˣ�ʹ����������洢������߶ȣ����ұ����߶� 
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
				if (stk.empty()) {		//û������ǽ�� 
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
