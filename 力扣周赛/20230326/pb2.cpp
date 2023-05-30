#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int binarySearch(vector<int> &primes, int target) {
	int left = -1, right = primes.size();
	while (left + 1 < right) {
		int mid = left + (right-left)/2;
		if (primes[mid] < target) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left == -1 ? 0 : primes[left];
}

bool isAscendArray(vector<int> &nums, int &maxNum) {
	bool isAscend = true;
	for (int i = 1, n = nums.size(); i < n; i++) {
    	if (nums[i] > maxNum) {
    		maxNum = nums[i];
		}
		if (nums[i] <= nums[i-1]) {
			isAscend = false;		
		}
	}
	return isAscend;
}

bool primeSubOperation(vector<int>& nums) {
    int n = nums.size();
    int maxNum = nums[0];
	bool isAscend = isAscendArray(nums, maxNum);
	if (isAscend) {
		return true;
	}
	vector<int> primes;
	for (int i = 2; i <= maxNum; i++) {
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				isPrime = false; 
				break;
			}
		}
		if (isPrime) {
			primes.push_back(i);
		}
	}
	// 遍历每一个数进行操作
	bool ans = true;
	for (int i = 0; i < n; i++) {
		int maxPrime = 0;	
		if (i == 0) {
			maxPrime = binarySearch(primes,nums[i]);
		}
		else if (i > 0 && i < n-1) {
			maxPrime = binarySearch(primes,nums[i]-nums[i-1]);
		}
		
		nums[i] -= maxPrime;
	} 
	isAscend = isAscendArray(nums, maxNum);
	return isAscend;
}


// 2 3 5 7 11 13
// 8,11,16,13
// 1 4 3 13


int main() {
	vector<int> nums = {8,11,16,13};
	cout << primeSubOperation(nums) << endl;
	return 0;
}
