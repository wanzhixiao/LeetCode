#include<iostream>
#include<vector>
using namespace std;


/*
思路1：哈希map
	两次遍历 
	第一次++mp[nums[i]];
	第二次 判断mp[nums[i]] == 1 ？ return nums[i] : i++;
思路2：位运算
	a^a =  0; a^0 = 1; 0^0 = 0; 1^0 = 1; 1^1 = 0;
	
	位运算满足交换律和结合律 
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
