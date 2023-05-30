#include<iostream>
#include<functional>
#include<vector>
#include<unordered_map>
using namespace std;

const int inf = 0x3f3f3f3f;
typedef long long LL;
typedef vector<vector<int>> VVI;
typedef vector<int> V;
typedef pair<int,int> PII; 


//第一题 
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int sum = 0;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
            if (i>0 && s[i-1]=='1' && s[i] == '0') {
                cnt0 = 1;
                cnt1 = 0;
            }
            if (cnt0 >= cnt1) {
                ans = max(ans, 2*cnt1);
            }
            
        }
        return ans;
    }
    
    //第二题 
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<int,int> cnt;
        
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        int num = 0;
        
        while(true) {
            vector<int> vec;
            
        	while (cnt.size()) {
        		
        		num++;
			}
            
//            for (auto it = cnt.begin(); it != cnt.end() && cnt.size() > 0; ++it) {
//                num++;
//                vec.push_back(it->first);
//                --cnt[it->first];
//                if (cnt[it->first] == 0) {
//                    cnt.erase(it->first);
//                }
//            }

//            ans.push_back(vec);
//            if (num == n) {
//                break;
//            } 
        }
        return ans;
    }
};

   //第二题 
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        cnt = defaultdict()
        for num in nums:
            if num in cnt:
                cnt[num] += 1
            else:
                cnt[num] = 1
        s = set(nums)
        c = 0
        ans = []
        while True:
            arr = []
            for a  in s:
                if cnt[a] > 0:
                    cnt[a] -= 1
                    arr.append(a)
                    c += 1
                    
            ans.append(arr)
            if c == n:
                break
        
        return ans

//第三题 
class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        n = len(reward1)
        idx = list(range(n))
        ans = 0
        
        def dfs(i, path):
            nonlocal ans
            if i == n:
                if len(path) == k:
                    #计算总分
                    s1 = 0
                    for j in path:
                        s1 += reward1[j]
                    diff = list(set(idx).difference(set(path)))
                    s2 = 0
                    for j in diff:
                        s2 += reward2[j]
                    ans = max(ans, s1+s2)

                    # print(path, diff, ans)
                return
            
            #不吃第i块
            dfs(i+1, path)
            
            #吃第i块
            dfs(i+1, path+[i])
            
        dfs(0, [])
        return ans
        
        
class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        n = len(reward1)

        ans = 0
        
        # s1, s2 = sum(reward), sum(reward2)
        @cache
        def dfs(i, cnt, s1,s2):
            nonlocal ans
            if i == n:
                # if len(path) == k:
                #     #计算总分
                #     s1 = 0
                #     for j in path:
                #         s1 += reward1[j]
                #     diff = list(set(idx).difference(set(path)))
                #     s2 = 0
                #     for j in diff:
                #         s2 += reward2[j]
                #     ans = max(ans, s1+s2)

                    # print(path, diff, ans)

                if cnt == k:
                    ans = max(ans, s1+s2)

                return
            
            #不吃第i块
            dfs(i+1, cnt, s1, s2+reward2[i])
            
            #吃第i块
            dfs(i+1, cnt+1, s1+reward1[i], s2)
            
        dfs(0, 0, 0, 0)
        return ans
    
/*
[54,59,94,87,32,10,55,44,21,73,12,70,89,49,13,34,78,20,20,75,90,44,48,74,78,32,70,76,79,49,50,69]
[78,43,69,22,32,67,65,38,51,4,21,27,82,61,12,85,62,60,67,16,22,3,5,16,13,35,13,41,72,85,20,54]
17
*/

//第三题 
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> d(n,0);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            d[i] = reward1[i] - reward2[i];
            // 一开始假设都是第二只老鼠吃掉的
            ans += reward2[i];
        }
        sort(d.begin(), d.end(), [](int &a, int &b) {return a>b;});


        // r2[i] + diff[i]  , 溢出的部分为给第一只老鼠带来的收益； 否则分配给第二只老鼠, r2[j]
        for (int i = 0; i < k; i++) {
            ans += d[i];
        }
        return ans;
    }
};


int main() {
	vector<int> nums = {1,3,4,1,2,3,1};
	Solution solu;
	vector<vector<int>> ans = solu.findMatrix(nums);
	return 0;
} 
