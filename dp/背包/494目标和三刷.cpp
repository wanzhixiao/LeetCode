#include<iostream>
#include<vector> 
#include <numeric>
#include<string.h>
using namespace std;


/*
P : ����ǰ���+�����ֺͣ�N����ǰ���-�����ֺ�
S : ���������е����ֺ� 
1: P+N =  S
2: P-N = target
 1ʽ-2ʽ�ã�
 2N = S - target;   N = (S-target)/2
 
 ��ΪN > 0�� ���� S-target > 0;
 ���ң� N % 2 == 0,  ��N %2 == 1, ���� P+N != S;  ��Ϊ P=N , 2P=2N=S  
 
 �Զ����£� ��i���������Ż��߼ӷ���
 �ݹ���ֹ����	i
 	�ݹ���ֹʱ���ж�N�Ƿ�==0�� �����0�� �����Path��������ϣ� ans++; 
 
*/ 

class Solution {
private:
	int ans = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    	int n = nums.size()-1;
    	int sum = accumulate(nums.begin(), nums.end(), 0);		// func���Զ���ĺ��������Զ�nums�е�ÿ�������в��� 
		int diff = sum + target;
		
		if (diff < 0 || diff%2) {
			return 0;
		}

		int N = diff/2;
		ans = dfs(nums, n, N);
		return ans; 
    }
    
    int dfs(vector<int> &nums, int n, int target) {
    	if (n < 0) {
    		if (target == 0) {
    			ans++; 
    			return 1;
			}
			return 0;
		}
		if (target < nums[n]) {
			return dfs(nums, n-1, target);
		}
		int res = 0;
		res += dfs(nums, n-1, target-nums[n]);
		res += dfs(nums, n-1, target+nums[n]);
		return res;
	}
};

int main() {
	Solution solu;
	vector<int> nums = {1,1,1,1,1};
	int target = 3;
	
	cout << solu.findTargetSumWays(nums, target) << endl;
	
	return 0;
}

