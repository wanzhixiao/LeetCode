#include<iostream>
#include<vector>
#include<stack>
using namespace std;


/*
1,3,3 
3,3,1,3
3,3,1,3,3
注意nums[mid] == nums[right] 的情况是 right = right - 1 
*/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0, right = n-1;
        while (left < right) {          // [left, right);
            int mid = (left + right) >> 1;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                right = mid;
            } else {
                right = right - 1;
            }
        }
        return numbers[left];
    }
};

int main() {
	vector<int> nums = {3,3,1,3,3};
	Solution solu;
	cout << solu.minArray(nums) << endl;
	return 0;
}
