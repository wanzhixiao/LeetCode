#include<iostream>
#include<vector>
using namespace std;


/*
˼·1����ϣmap
	���α��� 
	��һ��++mp[nums[i]];
	�ڶ��� �ж�mp[nums[i]] == 1 �� return nums[i] : i++;
˼·2��λ����
	a^a =  0; a^0 = 1; 0^0 = 0; 1^0 = 1; 1^1 = 0;
	
	λ�������㽻���ɺͽ���� 
	a^b^c = a^c^b = b^c^a
	1,2,2,4,4
	1^2^2^4^4 = 2^2^4^4^1  =  (2^2)^(4^4)^1 = 0^0^1 = 1;
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		for (int i = 1;i<nums.size(); i++) {
			nums[0] ^= nums[i];
		}
		return nums[0];
    }
};

int main () {
	cout << (0^0) << endl;
	Solution solu;
	vector<int> nums = {4,2,2,3,4};
	cout << solu.singleNumber(nums) << endl; 
	
	int a = 1;
	while (a < 16) {
		a = a<<1;
		cout << a << endl;
	}
	return 0;
} 
