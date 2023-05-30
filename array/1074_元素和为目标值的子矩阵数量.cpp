#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;
/*
求的是列子矩阵的和 
sum[1] = a[0][1] + a[1][1]+ ... + a[n-1][1]
*/

class Solution {
private:
    int S[110][110];
    int m = 0;
    int n = 0;
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int sum[101] = {0};
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    sum[k] += matrix[j][k];
                }
                ans = ans + targetSum(sum,target,n);
            }
        }
        

        //解法，找sum-target的个数，sum表示以i,j为右下角的矩阵的和；
        // int k = sum - target;
        // if (mp.count(k)) {
        //     ans += k;
        // }
        // ++mp[sum];

        // //如何枚举左上和右下的坐标？
        return ans;
    }

    int targetSum(int *nums, int target, int n) {
        unordered_map<int,int> mp{{0,1}};
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            // cout <<nums[i]<<" ";
            sum += nums[i];
            int k = sum - target;
            if (mp.count(k)) {
                ans += mp[k];
            }
            ++mp[sum];
        }
        // cout <<endl<<" "<<ans << endl;
        return ans;
    }
};

int main() {
	vector<vector<int>> matrix = {{0,1,0},{1,1,1},{0,1,0}};
	int target = 0;
	
	Solution solu;
	cout << solu.numSubmatrixSumTarget(matrix,target) << endl;
	
	return 0;
}
