#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size()-1;
        for (; i <= j; i++, j--) {
        	int left = nums[i];
	        int right = nums[j];
    		if (i != j) {
	            int bit = 1;
	            while (right != 0) {
	                right = right / 10;
	                bit *= 10;
	            }
	            ans += left *bit + nums[j];
			} else {
				ans += left;
			}
            cout << ans << endl;
        }
        return ans;
    }
};

int main() {
	vector<int> nums = {5,14,13,8,12};
	Solution solu;
	cout << solu.findTheArrayConcVal(nums) << endl;
	return 0;
}
