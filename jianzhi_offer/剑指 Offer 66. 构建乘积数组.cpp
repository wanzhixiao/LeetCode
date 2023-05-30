#include<iostream>
#include<cmath>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    int memo1[100005];
    int memo2[100005];
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ans;
        memset(memo1,-1,sizeof(memo1));
        memset(memo2,-1,sizeof(memo2));
        for (int i = 0; i < a.size(); i++) {
        	int right = dfs1(a,i+1);
        	int left = dfs2(a,i-1);
            int res = left * right;
            ans.push_back(res);
        }
        return ans;
    }

    int dfs1(vector<int> &a, int idx) {
        if (idx >= a.size() || idx<0) {
            return 1;
        }
        if (memo1[idx] != -1) {
            return memo1[idx];
        }
        int right = a[idx] * dfs1(a,idx+1);
        memo1[idx] = right;
        return right;
    }
    
    int dfs2(vector<int> &a, int idx) {
        if (idx >= a.size() || idx<0) {
            return 1;
        }
        if (memo2[idx] != -1) {
            return memo2[idx];
        }
        int left = a[idx] * dfs2(a,idx-1);
        memo2[idx] = left;
        return left;
    }
    
    
    vector<int> constructArr1(vector<int>& a) {
    	int n = a.size();
    	vector<int> product(n,0);
    	product[0] = a[0];
    	for (int i = 1; i < n; i++) {
            if (a[i] == 0) {
                product[i] = 1;
            } else {
	            product[i] = product[i-1] * a[i];
            }
            cout << product[i] << " ";
		}
		cout << endl;
		
		vector<int> ans(n,0);
//		for (int i = 0; i < n; i++) {
//			int left = (i>0) ? product[i-1] : 1;
//			int right = (i < n-1) ? product[n-1]/product[i] : 1;
//			ans[i] = left * right;
//		}
		return ans;
	}	 
};

int main() {
	Solution solu;
	vector<int> a = {1,2,0,4,5}; 
	vector<int> ans = solu.constructArr(a);
	for (int &x : ans) {
		cout << x << " ";
	}
	cout << endl; 
	return 0;
}
