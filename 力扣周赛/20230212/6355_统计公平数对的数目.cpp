#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	//暴力法 
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
//		vector<int> arr(nums.begin(), nums.end());
//		sort(arr.begin(),arr.end());
		long long ans  = 0;
		for (int i = 0 ; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				cout << nums[i] << " " << nums[j] << endl;
				if ((nums[i] + nums[j] >= lower) && (nums[i] + nums[j] <= upper)) {
					ans++;
				} 
			}
		}
		return ans;
    }
    
    //优化内层循环 
    long long countFairPairs1(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
		vector<int> arr(nums.begin(), nums.end());
		sort(arr.begin(),arr.end());
		long long ans  = 0;
		for (int i = 0 ; i < n; i++) {
//			for (int j = i+1; j < n; j++) {
//				cout << nums[i] << " " << nums[j] << endl;
//				if ((nums[i] + nums[j] >= lower) && (nums[i] + nums[j] <= upper)) {
//					ans++;
//				} 
//			}
			


		}
		return ans;
    }
    
    long long countFairPairs2(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
		long long ans  = 0;
		vector<int> presum(n,0);
		presum[0] = nums[0];
		for (int i = 1; i < n; i++) {
			presum[i] = presum[i-1] + nums[i];
		}
		
		int left = 0, right = 0;
		long long sum = 0;
		while (right < n) {
			sum += nums[right];
			while (left < right && sum>upper) {
				sum-=nums[left];
				if (sum >= lower && sum <= upper) {
					ans = right - left + 1; 
				}
				left++;
			} 
			++right;
		}
		
		return ans;
    }
    
    
    
    ////////////////////https://www.bilibili.com/video/BV1GY411i7RP/?spm_id_from=333.880.my_history.page.click&vd_source=843e98298bc70b0e35331918314486ce
        long long countFairPairs3(vector<int>& nums, int lower, int upper) {
    	int n = nums.size();
		long long ans = 0;
		
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n-1; i++) {
			int x = lower-nums[i];			//找到第一个大于等于x的下标 
			int y = upper-nums[i];			//找到第一个大于>=y的下标 
			
			if (x > nums[n-1] || y < nums[i+1]) {
				continue;
			}
			int l = bisect_left(nums, x, i);
			int r = bisect_right(nums, y, i);
			ans += (r - l);
		}
		return ans;
    } 
    
    int bisect_left(vector<int> &nums, int x, int start) {
    	int left = start, right = nums.size();
    	while (left + 1 < right) {
    		int mid = left + (right - left)/2;
    		if (nums[mid] < x) {
    			left = mid;
			} else {
				right = mid;
			}
		}
		return right;
	} 
    
    int bisect_right(vector<int> &nums, int x, int start) {
    	int left = start, right = nums.size();
    	while (left + 1 < right) {
    		int mid = left + (right - left)/2;
    		if (nums[mid] <= x) {
    			left = mid;
			} else {
				right = mid;
			}
		}
		return right;
	} 
};

int main() {
	//nums = [0,1,7,4,4,5], lower = 3, upper = 6
	vector<int> nums = {0,0,0,0,0,0};
	int lower = 0, upper = 0;
	Solution solu;
	cout << solu.countFairPairs3(nums, lower, upper);
	
	return 0;
}
