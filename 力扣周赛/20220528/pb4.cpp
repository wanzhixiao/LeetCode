#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
    	int m = mat.size(), n = mat[0].size();
    	vector<pair<int,int>> out;
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			bool flag = false;
    			for (int k = i-1; k >=0; k--) {
    				if (mat[k][j]>mat[i][j]) {
    					out.push_back({i,j});
    					flag = true;
    					break;
					}
				}
				if (!flag) {
					for (int k = i+1; k < m; k++) {
						if (mat[k][j]>mat[i][j]) {
	    					out.push_back({i,j});
	    					flag = true;
	    					break;
						}
					}	
				}

				if (!flag) {
					for (int k = j-1; k >= 0; k--) {
						if (mat[i][k]>mat[i][j]) {
	    					out.push_back({i,j});
	    					flag = true;
	    					break;
						}
					}	
				}

				if (!flag) {
					for (int k = j+1; k < n; k++) {
						if (mat[i][k]>mat[i][j]) {
	    					out.push_back({i,j});
	    					flag = true;
	    					break;
						}
					}
				}
				
			}
		}
	
		int ans = 1;
		for (auto p : out) {
			int x = p.first, y = p.second;
			vector<vector<int>> dis(m,vector<int>(n,-1));
			queue<pair<int,int>> q;
			q.push({x,y});
			dis[x][y] = 1;
			while (!q.empty()) {
				pair<int,int> p1 = q.front();
				q.pop();
				int x1 = p1.first, y1 = p1.second;
//				cout << x1 << " -11- " << y1 << endl;
				for (int i = x1-1; i >= 0; i--) {
					if (mat[i][y1] > mat[x1][y1]){
                        if (dis[x1][y1]+1 > dis[i][y1]) {
                            dis[i][y1] = dis[x1][y1]+1;
                            q.push({i,y1});
                        }
						ans = max(dis[i][y1],ans);
					}
				} 
				for (int i = x1+1; i < m; i++) {
					if (mat[i][y1] > mat[x1][y1]){
                        if (dis[x1][y1]+1 > dis[i][y1]) {
                            dis[i][y1] = dis[x1][y1]+1;
                            q.push({i,y1});
                        }
						ans = max(dis[i][y1],ans);
					}
				}
				for (int j = y1-1; j >= 0; j--) {
					if (mat[x1][j] > mat[x1][y1]){
                        if (dis[x1][y1]+1 > dis[x1][j]) {
                            dis[x1][j] = dis[x1][y1]+1;
                            q.push({x1,j});
                        }
						ans = max(dis[x1][j],ans);
					}
				}
				for (int j = y1+1; j < n; j++) {
					if (mat[x1][j] > mat[x1][y1]){
				        if (dis[x1][y1]+1 > dis[x1][j]) {
                            dis[x1][j] = dis[x1][y1]+1;
                            q.push({x1,j});
                        }
						ans = max(dis[x1][j],ans);
					}
				}
			}
		}
		return ans;
    }
};

//[[-8,4,9,-1]]

int main() {
	vector<vector<int>> grid = {{3,1},{3,4}};
	Solution solu;
	cout << solu.maxIncreasingCells(grid) << endl;
	return 0;
} 
