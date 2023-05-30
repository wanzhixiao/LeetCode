#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n+1,0), post(n+1,0);
	vector<int> ans;
	
    pre[0] = 1, post[n] = 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] * nums[i-1];
        post[n-i] = post[n-i+1] * nums[n-i];
//        cout << pre[i] << " " << post[n-i] << endl;
    }
    
    for (int i = 1; i <= n; i++) {
//    	cout << pre[i] << " " << post[i] << endl;
    	int product = pre[i-1] * post[i];
		ans.push_back(product);
	}

	return ans;
}

int main() {
	vector<int> nums = {-1,1,0,-3,3};
	vector<int> ans = productExceptSelf(nums);
	for (int &x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
