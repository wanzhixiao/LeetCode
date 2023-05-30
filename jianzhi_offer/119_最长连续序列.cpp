#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;


/*
题目：给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

思路1： dfs + hashset
先用hashset存放每个数 : 去重 
用dfs遍历每个数num-1, num+1; 遍历过程中，num存在hashset中，则删除该数 

递归终止条件： hash.find(nums) == hash.end()
	hash.erase(nums);
	dfs(hash,nums+1)+dfs(hash,nums-1)+1; 

思路2：bfs+hashset, 思路同上
思路3：并查集 
*/

#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;


/*
题目：给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

思路1： dfs + hashset
先用hashset存放每个数 : 去重 
用dfs遍历每个数num-1, num+1; 遍历过程中，num存在hashset中，则删除该数 

递归终止条件： hash.find(nums) == hash.end()
	hash.erase(nums);
	dfs(hash,nums+1)+dfs(hash,nums-1)+1; 

思路2：bfs+hashset, 思路同上
思路3：并查集 
*/

class UnionFind{
public:
    vector<int> root;
    vector<int> cnts;

    UnionFind(int n) {
        root.resize(n);
        cnts.resize(n);
        for (int i = 0; i < n; i++) {
            root[i] = i;
            cnts[i] = 1;
        }
    }

    int findNum(int x) {
        if (x != root[x]) {
            root[x] = findNum(root[x]);
        }
        return root[x];
    }
    void unionNum(int x,int y) {
        int rootX = findNum(x);
        int rootY = findNum(y);

        if (rootX == rootY) {
            return;
        }
        if (cnts[rootX] > cnts[rootY]) {
            root[rootY] = rootX;
            cnts[rootX] += cnts[rootY];
        } else {
            root[rootX] = rootY;
            cnts[rootY] += cnts[rootX];
        }
    }

    int getMaxNum() {
        int ans = 0;
        for (int i = 0; i < root.size(); i++) {
            if (i == root[i]) {
                ans = ans > cnts[i] ? ans : cnts[i];
            }
        }
        return ans;
    }
}; 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		set<int> hash;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			hash.insert(nums[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (hash.find(nums[i]) != hash.end()) { 
				ans = max(ans, dfs(hash,nums[i]));
			}
		}
		return ans;
    }
    
    int dfs(set<int> &hash, int num) {
    	if (hash.find(num) == hash.end()) {
    		return 0;
		}
		hash.erase(num);
		return dfs(hash,num+1) + dfs(hash,num-1) + 1;
	}
	
	int longestConsecutive2(vector<int>& nums) {
		set<int> hash;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			hash.insert(nums[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (hash.find(nums[i]) != hash.end()) { 
				ans = max(ans, bfs(hash,nums[i]));
			}
		}
		return ans;
    }
    
    int bfs(set<int> &hash,int x) {
    	queue<int> q;
    	q.push(x);
    	int cnt = 0;
    	while (!q.empty()) {
    		int front = q.front();
    		++cnt;
    		hash.erase(front);
    		q.pop();
    		if (hash.find(front+1) != hash.end()) {
    			q.push(front+1);
			}
			if (hash.find(front-1) != hash.end()) {
				q.push(front-1);
			}
		}
    	return cnt;
	}
	
	int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        UnionFind ufind(n);
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) continue;
            if (mp.find(nums[i]+1) != mp.end()) {
                ufind.unionNum(i,mp[nums[i]+1]);
            }
            if (mp.find(nums[i]-1) != mp.end()) {
                ufind.unionNum(i,mp[nums[i]-1]);
            }
            mp[nums[i]] = i;
        }
        return ufind.getMaxNum();
    }
    
    //动态规划 
    int MLS(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> dp(arr.size(),1);
        int maxcnt = 0;
        for(int i = 1;i < arr.size();i++)
        {
            if(arr[i - 1] + 1 == arr[i])
                dp[i] = dp[i - 1] + 1;
            else if(arr[i - 1] == arr[i])
                dp[i] = dp[i - 1];
            maxcnt = max(maxcnt,dp[i]);
        }
        return maxcnt;
    }
};

int main() {
	vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
	Solution solu;
	cout << solu.longestConsecutive3(nums) << endl;


/*
    vector<int> vect;        
    vect.reserve(100);    //分配100个空间
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    cout<<vect.size() << " " << vect.capacity() <<endl; //size = 4, capcity = 100
    
    
    vect.clear();
    vect.push_back(1);
    vect.push_back(2);
    vect.resize(100);    //分配100个空间
    cout<<vect.size() << " " << vect.capacity() <<endl; //size = 100, capcity = 100
    cout << vect[10] << endl;		//0
*/
	return 0;
} 

/*
并查集：
https://blog.csdn.net/weixin_43207056/article/details/106801932 
*/
