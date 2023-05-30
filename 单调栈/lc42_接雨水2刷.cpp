#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
������� = ��*�� 
�� = min (height[right], height[left]) - height[cur]
�� = min(right-left-1)

��Ҫά��һ�������ݼ�ջ��ջ�ڵ�Ԫ��Ϊ���ӵĸ߶ȣ������εݼ� 
*/ 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int h = height[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int area = (i-stk.top()-1)*(min(height[i],height[stk.top()]) -h);
                ans = ans + area;
            }
            stk.push(i);
        }
        return ans;
    }
};

int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution solu;
	cout <<  solu.trap(height) << endl;
	return 0; 
} 
