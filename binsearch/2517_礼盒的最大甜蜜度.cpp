#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*
当甜蜜度越大的时候,满足条件的数组越少，具有一定的单调性
*/ 
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(),price.end());
        int left = 0, right = (price[n-1]-price[0]) / (k-1) + 1;
        
        while (left + 1 < right) {	//(left, right)
        	int mid = left + (right-left)/2;
        	if (check(price, mid, k)) {
        		left = mid;
			} else {
				right = mid;
			}
		}
		return left;
    }
    bool check(vector<int> &price, int cap, int k) {
    	int n = price.size(), cnt = 1;
    	int pre = price[0];
    	for (int i = 1; i < n; i++) {
    		if (price[i] - pre >= cap) {	//选k组,两两之间的gap大于等于cap的糖果 
    			cnt++;
    			pre = price[i];
			}
			if (cnt == k) {					//选k组 
				return true; 
			}
		}
		return false;
	}
};

int main() {
	vector<int> price = {13,5,1,8,21,2};
	int k = 3;
	Solution solu;
	
	cout << solu.maximumTastiness(price, k);
	
	
	return 0;
} 

/*
参考：
https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/solution/er-fen-sou-suo-tu-jie-go-by-yzero-v-kc3i/
https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/solution/by-lcfgrn-73ui/
 
*/
