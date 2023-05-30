#include<iostream>
#include<vector>
#include<string> 
using namespace std;

/*
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
思路1： 双指针, 存在问题 
	s1[i] = s3[j] ++i, ++j
	s2[k] = s3[j] ++i, ++k
思路2：动态规划
	dp[i][j]表示 s1[0...i] (i+1个字符)和s2[0...j] (j+1个字符)能否组成 s3[0...i+j] (i+j+2个字符)
	
	dp[i][j] = dp[i-1][j] && (s1[i] == s3[p]) || 	dp[i][j-1] && (s2[j] == s3[p])	//p = i+j-1
	
	dp[0][0] = true;
*/ 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int p1 = 0, p2 = 0, p3 = 0;
        int m = s1.length(), n = s2.length(), t = s3.length();

        if (m + n < t) {
            return false;
        }

        while (p1 < m && p2 < n) {
            cout << (s3[p3] == s1[p1]) << " " << (s3[p3] == s2[p2]) << endl;
  			if (s3[p3] == s1[p1] && s3[p3]==s2[p2]) {
				if ( p1 < p2) {
                    s3[p3] = s1[p1];
                    ++p1;
                } else {
                    s3[p3] = s2[p2];
                    ++p2;
            	}
			} else if (s3[p3] == s1[p1]) {
                ++p1;
            } else if (s3[p3] == s2[p2]) {
                ++p2;   
            } else {
                return false;
            }
            ++p3;
        }   
        cout << "p1 = " << p1 << " p2 = " << p2 << " t = "<< t << endl;
        if (p1+p2 == t) {
            return true;
        }
        // --p3;
        while (p1 < m && p3 < t) {
            if (s3[p3] == s1[p1]) {
                ++p1;
            } else {
                return false;
            }
            ++p3;
        }
        cout << s3[p3] << " " << p3 << " " << t << " " <<s2[p2]  << " "<< s1[p1] << endl;
        while (p2 < n && p3 < t) {
            if (s3[p3] == s2[p2]) {
                ++p2;
            } else {
                return false;
            }
            ++p3;
        }
        return true;
    }
    
    bool isInterleave2(string s1, string s2, string s3) {
   		int p1 = 0, p2 = 0, p3 = 0;
        int m = s1.length(), n = s2.length(), t = s3.length();

        if (m + n != t) {
            return false;
        }
        // dp[i][j] 表示s1[0...i] ... s2[0...j]能否组成 s3[0...i+j+1]
        // dp[i][j] = dp[i][j-1] && s1[i] == s3[i+j] || dp[i-1][j] && s2[j]==s3[i+j]
        // dp[0][0] = false;

        vector<vector<int>> dp(m+1,vector<int>(n+1,false));
        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int p = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= dp[i-1][j] && s1[i-1] == s3[p];
                }
                if (j > 0) {
                    dp[i][j] |= dp[i][j-1] && s2[j-1] == s3[p];
                }
            }
        }
        return dp[m][n];
		
    }
};

int main() {
	string s1 = "aabc";
	string s2 = "abad";
	string s3 = "aabadabc";
	
	Solution solu;
	cout << solu.isInterleave2(s1,s2,s3) << endl; 
	return 0;
} 
