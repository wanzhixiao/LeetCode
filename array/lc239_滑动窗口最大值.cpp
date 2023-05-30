#include<iostream>
#include<vector>
#include<queue>
#include<stack> 
using namespace std;

/*
˼·1����������ö��ÿ������Ϊk�������飬���ÿ���������е����ֵ����ʱ 
˼·2���������ڣ�ά��һ����СΪk�Ļ�������
	���ڴ���ʲô������Ϊk��������
	��ʱ�ƶ���ָ�룺right - left >= k  
	��ʱ�ƶ���ָ�룺 right - left < k 
	����󴰿��ڵ����ֵ 
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
        //ʹ��˫����С�
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            //������ڳ����Ѿ�������k��������ߵ�Ԫ���Ƴ�
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            //�Ӻ���ǰ�Ƴ����ж�����С�ڵ�ǰԪ�ص�Ԫ��
            while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            //�ڶ�������ӵ�ǰԪ��
            dq.push_back(i);
            //������ڳ����Ѿ�������k�����ڽ���в������ֵ(deque��ǰ���Ԫ��)
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
