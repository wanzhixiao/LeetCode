#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

/*
// bbaeixoubb -> ['aei', 'ou']
// cuaieuouac -> ['uaieuoua'] 

统计元音字符串的个数
思路：滑动窗口 + map 
	1. 提取字符串中的元音子字符串，并存到vector中
	2. 遍历vector中的元音字符串；
	3. 使用滑动窗口
		窗口内代表什么： 满足条件的元音字符串
		何时移动右指针:  
		何时移动左指针， 当map[s[left]] > 1时， 将map[s[left]]--, ++left
		ans += left + 1; 统计的是以左指针为起点的元音字符串的数量 
*/

class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int> mp;
        string s = "";
        vector<string> vec;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                s += word[i];
            } else {
                vec.push_back(s);
                s = "";
            }
        }
        if (s.size()>0){
            vec.push_back(s);
        }

        int ans = 0;

        for (string &s : vec) {
            // cout << s << " " << endl;
            int n = s.length();
            int left = 0, right = 0;
            mp.clear();

            while (right < n) {
                char ch = s[right];
                ++mp[ch];
                while (mp[s[left]] > 1) {
                    --mp[s[left]];
                    ++left;
                } 
                if (check(mp)) {
                	cout << " meet : "<< s.substr(left,right-left+1) << endl;
                	//细节：为什么是left + 1, 因为如果left前也是元音字符，加上前面被抛弃的left的个数，也能组成left个元音字符串
					// + 1 表示的是当前的s[left...right]组成的字符串满足元音字符串条件 
					// aaeiou, 的元音字符串有aaeiou, aeiou 
                    ans += left + 1;
                    cout << "ans = " << ans << " left = " << left << endl;
                }
              	cout << s.substr(left,right-left+1) << endl;
                right++;
            }
        }
        return ans;
    }

    bool check(unordered_map<char,int> &mp) {
        if (mp['a']>0  && mp['e']>0  && mp['i']>0  && mp['o']>0  && mp['u']>0){
            return true;
        }
        return false;
    }
};


/*

string s = "cuaieuouac";
vector<string> vec = ['uaieuoua']

u
ua
uai
uaie
aieu
 meet : aieuo
ans = 2 left = 1
aieuo
 meet : aieuou
ans = 4 left = 1
aieuou
 meet : ieuoua
ans = 7 left = 2
ieuoua

*/


int main() {
	string s = "cuaieuouac";
	Solution solu;
	cout << solu.countVowelSubstrings(s) << endl;
	
	return 0;
}
