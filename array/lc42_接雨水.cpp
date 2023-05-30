#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
42.����ˮ
��Ŀ: ����n���Ǹ�������ʾÿ�����Ϊ1�����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ 
˼·1������ջ
		��һ������ջ��������±� ����ջ�׵�ջ��Ԫ��ֵ���μ�С
		ջ��Ԫ�ش��ڵ�ǰԪ�أ���ջ��
		ջ��Ԫ��С�ڵ�ǰԪ�أ�ȡ��ǰջ��Ԫ�� �����������Ͱ�� (min(height[stk.top()],height[right]) - cutH)*(right-stk.top()-1) 
		
	��װˮ��ǰ�᣺���ߵ�Ͱ�����м��Ͱ��
	
	ϸ�ڣ���Ҫ���� stk.top() < right  , ������Ԫ���±���Ⱥ�˳��
	
˼·2����̬�滮 
	��װˮ��ǰ�᣺���ߵ�Ͱ�����м��Ͱ��
	�ֱ���ǰ����������ֵ���Ҳ����ֵ 
	Ȼ���ٱ���һ�Σ���min(������ֵ���Ҳ����ֵ��-height[i] 
*/
class Solution {
public:
    int trap(vector<int>& height) {
		int n = height.size();
        int left = 0, right = 0, ans = 0;
        stack<int> stk;
        while (right < n) {
            while (!stk.empty() && height[stk.top()] < height[right]) {
                int curH = height[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int minh = min(height[stk.top()],height[right]);
                int area = (right-stk.top()-1)*(minh-curH);
                ans = ans + area;
            }
            stk.push(right);
            right++;
        }
        return ans;
    }
    
    int trap2(vector<int>& height) {
		int n = height.size();
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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i],rightMax[i]) - height[i];
        }
        return ans;
    }
};

int main() {
	vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution solu;
	cout << solu.trap2(vec) << endl;
	return 0;
}
