#include<vector>
#include<iostream>
using namespace std; 

class Solution {
public:
    int maxLength(vector<string> &arr) {
        vector<int> masks;
        for (string &s : arr) {
            int mask = 0;
            for (char ch : s) {
                ch -= 'a';
                if ((mask >> ch) & 1) { // 若 mask 已有 ch，则说明 s 含有重复字母，无法构成可行解
                    mask = 0;
                    break;
                }
                mask |= 1 << ch; // 将 ch 加入 mask 中
            }
            if (mask > 0) {
                masks.push_back(mask);
            }
        }

        int ans = 0;
        function<void(int, int)> backtrack = [&](int pos, int mask) {
            if (pos == masks.size()) {
                ans = max(ans, __builtin_popcount(mask));
                return;
            }
            if ((mask & masks[pos]) == 0) { // mask 和 masks[pos] 无公共元素
                backtrack(pos + 1, mask | masks[pos]);
            }
            backtrack(pos + 1, mask);
        };
        backtrack(0, 0);
        return ans;
    }


// 二进制枚举 
private:
    int ans = 0;
public:
    int maxLength(vector<string>& arr) {
       
        // 计算每个字符串中字符的出现次数，看是否有重复，没有重复则把mask加到mask数组中
        int n = arr.size();
        vector<int> masks;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (char ch : arr[i]) {
                ch -= 'a';
                if ((mask >> ch) & 1) { //arr[i]字符串中存在重复的字符
                    mask = 0;
                    break;
                }
                // 将ch 添加到mask中
                mask |= (1 << ch);
            }
            if (mask) {
                masks.push_back(mask);
            }
        }
        int ans = 0;
        // dfs判断mask[i] & mask[pos] == 0, 选或者不选nums[pos]
        function<void(int,int)> f = [&](int mask, int pos) {
            if (pos == masks.size()) {
                int numOnes = 0;
                while (mask) {
                    //取出最右边的1
                    long long x = mask & (-mask);
                    mask -= x;
                    numOnes++;
                }
                ans = max(ans, numOnes);
                return;
            }
            //不选第pos个元素
            f(mask, pos+1);
            // 已拼接的字符串和第一个字符串没有重复元素
            if ((mask & masks[pos]) == 0) {
                //选第pos个元素
                f(mask|masks[pos], pos+1);
            }
        };
        f(0,0);
        return ans;
    }  
    
public:
	// 递推方法 
    int maxLength(vector<string>& arr) {
       
        // 计算每个字符串中字符的出现次数，看是否有重复，没有重复则把mask加到mask数组中
        int n = arr.size();

        //先置加入一个0
        vector<int> masks{0};

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (char ch : arr[i]) {
                ch -= 'a';
                if ((mask >> ch) & 1) { //arr[i]字符串中存在重复的字符
                    mask = 0;
                    break;
                }
                // 将ch 添加到mask中
                mask |= (1 << ch);
            }
            if (mask == 0) {
                continue;
            }

            for (int i = 0; i < masks.size(); i++) {
                if ((mask & masks[i]) == 0) {
                    // 没有冲突则将mask | masks[i]加入到mask数组中
                    masks.push_back(mask | masks[i]);
                    ans = max(ans, __builtin_popcount(mask | masks[i]));
                }
            }
        }
        return ans;
    }
};

/*
	int a = 1, b = 2, c = 3;
	int mask = 1<<a;
	cout << mask << endl;
	cout << (1<<b) << endl;
	mask |= (1<<b);					//  1<<2 = 4   2 |= 4 =    010 | 100 = 110
	mask |= (1<<c);
	cout << mask << endl;			//  1 1 1 0;			//从左至右，第1位，第2位，第3位都有1
	
	cout << (mask >> c) << endl; 	//剩下原来的最高位1   0001
	cout << (mask >> b) << endl; 	//剩下 0011 
	cout << (mask >> a) << endl;
	
	int d = 8;
	cout << (d & (-d)) << endl;     // 8 
*/


int main() {
	
	return 0;
}
