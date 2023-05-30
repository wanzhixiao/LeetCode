#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠


输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。


难点一：一看题就有感觉需要排序，但究竟怎么排序，按左边界排还是右边界排。
难点二：排完序之后如何遍历，如果没有分析好遍历顺序，那么排序就没有意义了。
难点三：直接求重复的区间是复杂的，转而求最大非重复区间个数。
难点四：求最大非重复区间个数时，需要一个分割点来做标记。


按区间右端点进行排序，
从左向右遍历，每次选取最小的右边界作为end, 记录count

例如
 [1,2],[2,3],[3,4],[1,3]
 按照右边界排序后：[1,2],[2,3],[1,3],[3,4]
 
 从第二个区间开始遍历每个区间
 	end = 2第一个区间的右端点 
 	[2,3] 
	end <= 2; count ++;  end = 3
	
	[1,3]
	end = 3 > 1; continue
	
	[3,4]
	end = 3 < = 3; count ++; end = 4
 遍历结束
 
 返回 interval.size() - count 
 
 
方法二：
	动态规划，类似最长递增子序列
	rj < li 时， li前面最多有多少个区间
	定义dp[i]表示以第i个区间结尾的区间 的无重叠区间个数
	if (intervals[j][1] <= intervals[i][0])
		dp[i] = max( dp[i], dp[j] + 1) 
	
	初始化
	dp[0...n] = 1;
*/

class Solution {
public:
	//对右边界排序，从左往右遍历，右边界越小越好，留给下一个区间的空间就越大 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int n = intervals.size();
		sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){return a[1] < b[1];});
		int end = intervals[0][1];
		int count = 1;
		for (int i = 1; i < n; i++) {
			if (end <= intervals[i][0]) {
				end = intervals[i][1];
				count++;
			}
		}
		return n - count;
    }
    
    //对左边界排序，从右往左遍历，左边界越大越好，留给上一个区间的空间就越大 
    int eraseOverlapIntervals2(vector<vector<int>>& intervals) {
		int n = intervals.size();
		sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){return a[0] < b[0];});
		int start = intervals[n-1][0];
		int count = 1;
		for (int i = n-2; i >= 0; i--) {
			if (start >=  intervals[i][1]) {
				start = intervals[i][0];
				count++;
			}
		}
		return n - count;
    }
    
    //动态规划
	int eraseOverlapIntervals3(vector<vector<int>>& intervals) { 
		int n = intervals.size();
		sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){return a[0] < b[0];});
		vector<int> dp(n,1);
		int tmax = 1;
		for (int i = 1; i < n; i++) {
//			for (int j = 0; j < i; j++) {
//				if (intervals[j][1] <= intervals[i][0]) {
//					dp[i] = max(dp[i], dp[j]+1);
//				}
//			}
//			
			int left = -1, right = i+1;
			while (left + 1 < right) { //[left,right)
				int mid = (left+right)/2;
				if (intervals[mid][1] <= intervals[i][0]) {
					left = mid;
				} else {
					right = mid;
				}
			}
			cout <<left << " " << i << endl;
			dp[i] = max(dp[i],dp[left]+1);
			
			tmax = max(dp[i],tmax);
		} 
		return n-tmax;
	}
};


/*
[[1,100],[11,22],[1,11],[2,12]]
*/

int main() {
	vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
	Solution solu;
	cout << solu.eraseOverlapIntervals3(intervals) << endl; 
	
	return 0;
} 
