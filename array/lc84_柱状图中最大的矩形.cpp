#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
��״ͼ�����ľ���
��Ŀ������ n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
���룺heights = [2,1,5,6,2,3]
�����10
���ͣ����ľ���Ϊͼ�к�ɫ�������Ϊ 10��[5,6] 5*2 = 10 

˼·1��������
˼·2������ջ
ά��һ�������ڵ���ջ��ջ�д�Ԫ�ص��±ꣻջ������һ��Ԫ����������ߵ�һ����ջ��С��Ԫ��
���Ҳ������һ����ջ��С��Ԫ�أ���ô��ջ��Ԫ�ص��������	���Ҳ�Ԫ���±�-ջ����ǰһ��Ԫ���±�-1��*ջ���±��Ӧ�ĸ߶� 
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMin(n,0);
        vector<int> rightMin(n,0);
        leftMin[0] = 0;
        rightMin[n-1] = n-1; 
        for (int i = 1; i < n; i++) {
        	leftMin[i] = heights[i] < heights[leftMin[i-1]] ? i : leftMin[i-1];
        	rightMin[n-1-i] = heights[n-1-i] < heights[rightMin[n-i]] ? n-1-i : rightMin[n-i];
		}
		for (int i = 0; i < n; i++) {
			int minH = max(heights[leftMin[i]],heights[rightMin[i]]);
		}
		return 0;
    }
    
    int largestRectangleArea2(vector<int>& heights) {
    	int n = heights.size();
    	stack<int> stk;
    	heights.push_back(-1);
    	int ans = 0;
    	for (int i = 0; i < n; i++) {
    		while (!stk.empty() && heights[i] < heights[stk.top()]) {
    			int idx = stk.top();
    			stk.pop();
    			int left = stk.empty() ? -1 : stk.top();   //���û�о��ε�ʱ��ջΪ�գ���Ϊ�ǵ�������ջ��˵�����ľ��θ߶ȶ���ջ����Ԫ��С����������Ϊ-1 
    			ans = ans > (i-left-1)*heights[idx] ? ans : (i-left-1)*heights[idx];
			}
			stk.push(i);
		}
    	return ans;
	}
};

int main() {
	vector<int> heights = {2,1,5,6,2,3};
	Solution solu;
	cout << solu.largestRectangleArea2(heights) << endl;
	return 0;
} 
