#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*
��С���
����һ�����Ե����䣬�����С�����ֵk��
������ֵk����check��������ָ�����ƣ���Сk
������ֵk������check��������ָ�����ƣ�����k

������Ҫ���һ����С�����ֵ	k 
*/ 

class Solution {
public:
  	int minimizeArrayValue(vector<int>& nums) {
            int left = 0, right = *max_element(nums.begin(), nums.end());
            while (left < right){ //[left, right)
                int mid = left + (right-left)/2;
                cout << left << " " << mid << " " << right << endl;
                if (check(mid,nums)) {
                    right = mid;
                } else {
                    left = mid+1;
                }
            }
        return left;
    }

    bool check(int limit, vector<int> nums) {
    	int n = nums.size();
    	//����������תΪlonglong�Σ���ֹԽ�� 
        vector<long long> A(n,0);
        for (int i = 0; i < n; i++) {
            A[i] = nums[i];
        }

        long long extra = 0;
    	for (int i = n-1; i >= 1; i--) {
            if (A[i] > limit) {
                long long det = A[i] - limit;		//��һ������ȥ��ǰ���Ե�ֵ 
                A[i] = limit;						//��ǰ�������ڳ��Ե�ֵ 
                A[i-1] += det;						//ǰһ�������ϳ��Ե�ֵ 
            }
		}
		printVec(A); 
		return A[0] <= limit;
	}
	
	bool check2(int limit, vector<int> &nums) {
		int n = nums.size();
        long long tmp = 0;
        for (int i = n-1; i >= 1; i--) {
            if (nums[i]+tmp > limit) {
                tmp = nums[i] - limit;
            } else {
                tmp = 0;
            }
        }
        return nums[0] + tmp <= limit;
	} 
	
    void printVec(vector<long long> &nums) {
    	for (int i = 0; i < nums.size(); i++) {
    		cout << nums[i] << " ";
		}
		cout << endl;
	}
  
};

int main() {
	vector<int> nums = {3,7,1,6};
	Solution solu;
	cout << solu.minimizeArrayValue(nums) << endl;
	return 0;
}
