#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct task {
	int startTime;
	int endTime;
	int parallelism;
}; 

int main() {
	int taskNum = 0;
	int startTime = 0, endTime = 0, parallelism = 0;
	cin >> taskNum;
	vector<task> taskList;
	for (int i = 0; i < taskNum; i++) {
		cin >> startTime >> endTime >> parallelism;
		taskList.push_back({startTime, endTime, parallelism});
	}
	
	sort(taskList.begin(), taskList.end(), [](task a, task b) { 
		return a.startTime < b.startTime;
	});
	
	vector<task> vec;
	vec.push_back(taskList[0]);
	
	while (true) {
		// 取vec的最后一个元素取根vec.size()+1及后面的元素做交集 
	}
	
	for (int i = 1; i < taskNum; i++) {
		if (vec.back().endTime >= taskList[i].startTime) {
			//[0,5] [2,3] -> [2,3] 
			//[0,5] [4,7] -> [4,7]
			vec.back().startTime = max(taskList[i].startTime, vec.back().startTime);
			vec.back().endTime = min(taskList[i].endTime, vec.back().endTime);
			vec.back().parallelism += taskList[i].parallelism; 
		} else {
			vec.push_back(taskList[i]);
		}
	}
	int ans = 0;
	for (int i = 0, n = vec.size(); i < n; i++) {
		cout << vec[i].startTime << " " << vec[i].endTime << " " << vec[i].parallelism << endl;
		ans += vec[i].parallelism;
	}
	cout << ans << endl;
	return 0;
}
