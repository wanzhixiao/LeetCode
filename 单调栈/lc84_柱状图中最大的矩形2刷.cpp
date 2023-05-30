#include<iostream>
#include<vector>
#include<stack>
using namespace std; 

/*
ά��һ����������ջ��ջ�д����ӵĸ߶�
����ǰԪ�ظ���ջ��Ԫ��ʱ��
��� = (i - stk.top()) * height[stk.top()];  
height[stk.top()]Ϊ��ǰ��͵ĸߣ����ֻ���� i��stk.top()���Ǹ߶�Ϊheight[stk.top()], w=i-stk.top() 

���룺heights = [2,1,5,6,2,3]
�����10

��6��������ҵ�������С���±���� w = (i - left - 1 ) * 6
left��ôȷ����

left = stk.empty() ? -1 : stk.top();
��ΪջΪ�գ������������Ӷ����Կ����߶ȱ�ջ�����Ӹ߶�С 

�������Ϊ������
1,2,3; ջ������գ�������Ҫ���Ҳ��һ��0 
*/ 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int ans = 0;
        stack<int> stk;
        heights.push_back(0);
        int n = heights.size();
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
            	int h = heights[stk.top()];
          		stk.pop();
          		int left = stk.empty() ? -1 : stk.top(); 	//������ӵ��±� 
                ans = max(ans, (i-left-1)*h);
            }
            stk.push(i);
        }
        return ans;
    }
};

/*
���� �� [2,1,2] 
ջԪ�صı仯
[2]					ans = 0
[1]					ans = max(ans,height[i]) = max(0,2) =  2
[1,2]               ans = 2
 [1]                ans = max(ans,height[stk.top()]*(3-stk.top())) = max(2,2*(3-2)) = 2
 [0] 				ans = max(ans,height[stk.top()]*(3-stk.top())) = max(2,1*(3-1)) = 2
 ��һ��2�Ѿ�����ջ�У� ��� ������������Ϊ2 
*/ 

int main() {
	vector<int> height = {2,1,2};
	Solution solu;
	cout << solu.largestRectangleArea(height) << endl;
	return 0;
}
