#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        int n = gifts.size();
        for (int i = 0; i < n; i++) {
        	q.push(gifts[i]);
		}
		long long ans = 0;
		for (int i = 0; i < k; i++) {
			q.push(sqrt(q.top()));
			q.pop(); 
		}
		while (!q.empty()) {
			ans = ans + q.top();
			q.pop(); 
		}
		return ans; 
    }
};

int main() {
	Solution solu;
	vector<int> gifts = {1,1,1,1};
	int k = 4;
	
	cout << solu.pickGifts(gifts, k) << endl;
	return 0;
} 
