#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
����: intervals = [[1,2],[2,3],[3,4],[1,3]]
���: 1
����: �Ƴ� [1,3] ��ʣ�µ�����û���ص�


����: intervals = [ [1,2], [2,3] ]
���: 0
����: �㲻��Ҫ�Ƴ��κ����䣬��Ϊ�����Ѿ������ص����ˡ�


�ѵ�һ��һ������ио���Ҫ���򣬵�������ô���򣬰���߽��Ż����ұ߽��š�
�ѵ����������֮����α��������û�з����ñ���˳����ô�����û�������ˡ�
�ѵ�����ֱ�����ظ��������Ǹ��ӵģ�ת���������ظ����������
�ѵ��ģ��������ظ��������ʱ����Ҫһ���ָ��������ǡ�


�������Ҷ˵��������
�������ұ�����ÿ��ѡȡ��С���ұ߽���Ϊend, ��¼count

����
 [1,2],[2,3],[3,4],[1,3]
 �����ұ߽������[1,2],[2,3],[1,3],[3,4]
 
 �ӵڶ������俪ʼ����ÿ������
 	end = 2��һ��������Ҷ˵� 
 	[2,3] 
	end <= 2; count ++;  end = 3
	
	[1,3]
	end = 3 > 1; continue
	
	[3,4]
	end = 3 < = 3; count ++; end = 4
 ��������
 
 ���� interval.size() - count 
 
 
��������
	��̬�滮�����������������
	rj < li ʱ�� liǰ������ж��ٸ�����
	����dp[i]��ʾ�Ե�i�������β������ �����ص��������
	if (intervals[j][1] <= intervals[i][0])
		dp[i] = max( dp[i], dp[j] + 1) 
	
	��ʼ��
	dp[0...n] = 1;
*/

class Solution {
public:
	//���ұ߽����򣬴������ұ������ұ߽�ԽСԽ�ã�������һ������Ŀռ��Խ�� 
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
    
    //����߽����򣬴��������������߽�Խ��Խ�ã�������һ������Ŀռ��Խ�� 
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
    
    //��̬�滮
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
