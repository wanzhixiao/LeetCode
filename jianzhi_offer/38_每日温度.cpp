#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
ÿ���¶�
˼·1: ������������forѭ����ÿ������һ���������
˼·2��ά��һ�������ݼ�ջ��ջ�д��������±� 
��nums[i]����ջ��Ԫ��ʱ��ջ��Ԫ�س�ջ ��������i - stk.top(), ���������� 
��nums[i]С��ջ��Ԫ��ʱ��nums[i]��ջ 

����: temperatures = [73,74,75,71,69,72,76,73]
���: [1,1,4,2,1,1,0,0]
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans;
        for(int i = 0; i < n-1; i++){
            int tmp = 0;
            for (int j = i+1; j < n; j++) {
                if (temperatures[i] < temperatures[j]) {
                    tmp = j-i;
                    break;
                }
            }
            ans.push_back(tmp);
        }
        ans.push_back(0);
        return ans;
    }
    
    vector<int> dailyTemperatures2(vector<int>& temperatures) {
   		int n = temperatures.size();
   		vector<int> ans(n,0);
   		stack<int> stk;
		for (int i = 0; i < n; i++) {
			while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
				int d = i - stk.top();
				ans[stk.top()] = d;
				stk.pop();
			}
			stk.push(i);
		}
		return ans;
    } 
};

int main() {
	vector<int> temporatures = {30,60,90};
	Solution solu;
	vector<int> ans = solu.dailyTemperatures2(temporatures);
	
	for (int &x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
