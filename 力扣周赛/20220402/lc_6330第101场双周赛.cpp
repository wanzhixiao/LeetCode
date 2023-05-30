#include<iostream>
#include<functional>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
	const int inf = 0x3f3f3f3f;
	typedef vector<vector<int>> VVI;
	typedef vector<int> V;
	typedef pair<int,int> PII; 
public:
	int findShortestCycle(int n, vector<vector<int>>& edges) {
    	VVI g(n);
    	for (V e: edges) {
    		int start = e[0], end = e[1];
    		g[start].push_back(end);
    		g[end].push_back(start);
		}
		std::function<int(int,int,VVI)> bfs = [](int start, int n, VVI g){
			int ans = 0x3f3f3f3f;
			vector<int> dis(n,-1);
            dis[start] = 0;
			queue<PII> q;
			q.push(make_pair(start,-1));		//	q.push(pair<int,int>(start,-1));	q.push({start,-1});
			
			while(!q.empty()) {
				PII p = q.front();
				int x = p.first, fa = p.second;
				q.pop();
				for (int y : g[x]) {
					if (y == fa) {
						continue;
					}
					if (dis[y] == -1) {
						dis[y] = dis[x] + 1;
						q.push({y,x});
					} else {
						return dis[x] + dis[y] + 1;
					}
				}
			}
			return ans;
		};
		int ans = inf;
		for (int i = 0; i < n; i++) {
			ans = min(ans, bfs(i, n, g));
		}
		return ans == inf ? -1 : ans;
    }
};

int main() {
	vector<vector<int>> edges = {{0,1},{0,2}};
	int n = 4;
	Solution solu;
	cout << solu.findShortestCycle(n,edges) << endl; 
	return 0;
}
