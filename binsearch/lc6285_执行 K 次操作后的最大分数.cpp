#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

typedef unsigned long long ULL;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int a,int b){return a<b;});
        int n = nums.size();
		ULL ans = 0;
		int number = 0;
		for (int i = 0; i < k; i++) {
			int val = nums[n-1];
			ans += val; 
			number =  (val+2)/3;
			cout << "nums.size()=" << nums.size() << " nums[n-1]= " << nums[n-1] << " number= " << number << " ans= " << ans << endl;
			int idx = binary_search2(nums,number);
			if (idx == n-1) {
				nums[n-1] = number;
			} else {
				nums.insert(nums.begin()+idx,number);
				nums.pop_back();
			}
		}
		return ans;
    }
    
    int binary_search2(vector<int> &nums, int target) {
    	int left = -1, right = nums.size();
    	while (left + 1 != right) {
    		int mid = (left + right)/2;
    		if (nums[mid] < target) {
    			left = mid;
			} else {
				right = mid;
			}
		}
		return left + 1 == nums.size() ? left : left + 1;
	}
	
	//使用最大堆实现 
	long long maxKelements2(vector<int>& nums, int k) {
        priority_queue<int> que;
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            que.push(nums[i]);
        }
        for (int i = 0;  i < k; i++) {
            int val = que.top();
            ans += val;
            que.pop();
            que.push((val+2)/3);
        }
        return ans;
    }
};

int main() {
	vector<int> nums = {0,1,2,3,5};
	nums.insert(nums.begin()+3,6);
	cout << nums[3] << " " << nums[4] << endl;
//	int k = 1;
//	Solution solu;
//	cout << 10e9 << endl;
	return 0;
}
