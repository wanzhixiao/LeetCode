#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
using namespace std;

/*
思路1：暴力法，枚举每个长度为k的子数组，求出每个子数组中的最大值；超时 
思路2：滑动窗口，维护一个大小为k的滑动窗口
	窗口代表什么，长度为k的子数组
	何时移动左指针：right - left >= k  
	何时移动右指针： right - left < k 
	如何求窗口内的最大值 
*/ 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if (n <= k) {
            int maxval = -10001;
            for (int i = 0; i < n; i++) {
                if (nums[i] > maxval) {
                    maxval = nums[i];
                }
            }
            ans.push_back(maxval);
            return ans;
        }
        for (int i = 0; i <= n-k; i++) {
            int maxval = -10001;
      		for (int j = i; j < i+k; j++) {
	                if (nums[j] > maxval) {
	                    maxval = nums[j];
	                }
            }
			ans.push_back(maxval);	
        }
        return ans;
    }
    
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    	vector<int> ans;
        int n = nums.size();
		int left = 0, right = 0;
		int maxidx = 0, maxnum = -10001;
		int pre = 0; 
		//4,3,2,1,0 
		while (right < n) {
			
			if (right-k+1 >= pre) {
				maxnum = maxnum > nums[right] ? maxnum : nums[right]; 
			} else {
				pre = pre + 1;
				maxnum = maxnum > nums[right] ? maxnum : nums[right]; 
			}
			cout << "pre = " << pre << " maxnum=" << maxnum << " right=" << right << " nums[right]=" << nums[right] << endl; 
			
			cout <<"right-k+1=" << right-k+1 << " left = "<< left << endl;
			if (right-k==left) {
				
				cout <<"maxnum="<< maxnum <<" right-k+1=" << right-k+1 << endl;
			} else if(right-k+1 > left){
				left++;
			} 
			right++;
		} 
		return ans;
	} 
	
	vector<int> maxSlidingWindow3(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
    
    vector<int> maxSlidingWindow4(vector<int>& nums, int k) {
        //使用双向队列。
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            //如果窗口长度已经超过了k，则将最左边的元素移除
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            //从后往前移除所有队列中小于当前元素的元素
            while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            //在队列中添加当前元素
            dq.push_back(i);
            //如果窗口长度已经到达了k，则在结果中插入最大值(deque最前面的元素)
            if (i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

int main() {
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	int k = 3;
	Solution solu;
	vector<int> ans = solu.maxSlidingWindow4(nums,k);
	for (auto &x : ans) {
		cout << x << " ";
	} 
	cout << endl;
	return 0;
} 
