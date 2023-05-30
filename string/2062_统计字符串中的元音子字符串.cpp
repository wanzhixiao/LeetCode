#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

/*
// bbaeixoubb -> ['aei', 'ou']
// cuaieuouac -> ['uaieuoua'] 

ͳ��Ԫ���ַ����ĸ���
˼·���������� + map 
	1. ��ȡ�ַ����е�Ԫ�����ַ��������浽vector��
	2. ����vector�е�Ԫ���ַ�����
	3. ʹ�û�������
		�����ڴ���ʲô�� ����������Ԫ���ַ���
		��ʱ�ƶ���ָ��:  
		��ʱ�ƶ���ָ�룬 ��map[s[left]] > 1ʱ�� ��map[s[left]]--, ++left
		ans += left + 1; ͳ�Ƶ�������ָ��Ϊ����Ԫ���ַ��������� 
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
                	//ϸ�ڣ�Ϊʲô��left + 1, ��Ϊ���leftǰҲ��Ԫ���ַ�������ǰ�汻������left�ĸ�����Ҳ�����left��Ԫ���ַ���
					// + 1 ��ʾ���ǵ�ǰ��s[left...right]��ɵ��ַ�������Ԫ���ַ������� 
					// aaeiou, ��Ԫ���ַ�����aaeiou, aeiou 
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
