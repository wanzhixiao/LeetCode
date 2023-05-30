#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
每日温度
思路1: 暴力法，两层for循环找每个数后一个更大的数
思路2：维护一个单调递减栈，栈中存放数组的下标 
当nums[i]大于栈顶元素时，栈顶元素出栈 ，并计算i - stk.top(), 存入结果数组 
当nums[i]小于栈顶元素时，nums[i]入栈 

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
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
