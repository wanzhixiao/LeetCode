#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> &nums, int i, int cur, int target) {
	if (i == nums.size()) {
		return cur == target;
	}
    if (cur == target) {
        return true;
    }
    if (cur > target) {
    	return false;
	}

    bool res = false;
    if (cur + nums[i] < target) {
    	cout << "+" << endl;
       res |= dfs(nums, i+1, cur+nums[i], target);
       if (res) {
            return true;
       }
    }
    if (cur - nums[i] > 0) {
    	cout << "-" << endl;
        res |= dfs(nums, i+1, cur-nums[i],target);
        if (res) {
            return true;
        }
    }
    if (cur * nums[i] > 0) {
    	cout << "*" << endl;
         res |= dfs(nums,i+1, cur*nums[i], target);
         if (res) {
            return true;
         }
    }

    if (cur / nums[i] > 0) {
    	cout << "/" << endl;
        res |= dfs(nums, i+1, cur/nums[i], target);
        if (res) {
            return res;
        }
    }
    return res;
}

bool bfs(vector<int> &nums) {
	int n = nums.size();
	bool visited[4] = {false}; 
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int a = q.front();
			q.pop();
			if (a==24) {
				return true;
			}
			if (!visited[0] && ()) {
				
			}
			if (!visited[1] )
		}
	}
}

int main() {
    vector<int> nums;
    int m = 0;
    for(int i = 0; i < 4; i++) {
        cin >> m;
        nums.push_back(m);
    } 
    cout << dfs(nums, 0, 0, 24) << endl;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")

/*
    
*/
                       
