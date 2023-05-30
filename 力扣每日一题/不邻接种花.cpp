#include<iostream>
#include<vector>
#include<functional>
using namespace std;




class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n+1,vector<int>());
        for (int i = 0, m = paths.size(); i < m; i++) {
            int v1 = paths[i][0], v2 = paths[i][1];
            g[v1-1].push_back(v2-1);
            g[v2-1].push_back(v1-1);
        }
        vector<int> ans(n);
        
        // ����ÿ����԰����ͳ�������ڵĻ�԰����ɫ��ǣ�����δ����ǵ���ɫ���ҵ�һ����ɫ����ǰ�Ļ�԰���б�ǣ�
        for (int i = 0; i < n; i++) {
        	
			//ͳ�������ڻ�԰����ɫ��� 
			vector<int> color(5,false);
			for (int x : g[i]) {
				cout <<i << " " << x<<" " <<ans[x] << endl; 
				color[ans[x]] = true;
			}
			for (int j = 1; j <= 4; j++) {
				if (!color[j]){
					ans[i] = j;
					break;
				}
			}
        }
        return ans;
    }
    
    //������ 
    vector<int> gardenNoAdj2(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n+1,vector<int>());
        for (int i = 0, m = paths.size(); i < m; i++) {
            int v1 = paths[i][0], v2 = paths[i][1];
            g[v1-1].push_back(v2-1);
            g[v2-1].push_back(v1-1);
        }
        vector<int> ans(n);
        for (int i = 0; i<n; i++) {
            for (int j=1; j<=4; j++) {
                bool flag = false;
                for (int x : g[i]) {
                    if (ans[x] == j) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    ans[i] = j;
                }
            }
        }
        return ans;
    }
    
    //ʹ��λ���� 
    vector<int> gardenNoAdj3(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n+1,vector<int>());
        for (int i = 0, m = paths.size(); i < m; i++) {
            int v1 = paths[i][0]-1, v2 = paths[i][1]-1;
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        vector<int> ans(n);
        for (int i = 0; i<n; i++) {
           	int mask = 1; 
           	for (int x : g[i]) {
           		mask |= (1<<ans[x]);
			}
			//�ӵ͵����ҵ���һ��1��λ��
			cout << (mask&(-mask)) << " " << (~mask) << endl;
//			int b = ~mask;
//			cout << b << endl;
//			int c = b & (-b);
//			ans[i] = c;
//			cout << i << " " << b << " " << mask << endl;
        }
        return ans;
    }
};

int main() {
	int n = 5;
	vector<vector<int>> edge = {{4,1},{4,2},{4,3},{2,5},{1,2},{1,5}} ;
	Solution solu;
		cout << (3&(-3)) << endl;
	vector<int> ans = solu.gardenNoAdj3(n,edge);

	for (int &x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
} 
