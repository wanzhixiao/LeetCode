#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef unsigned long long ULL;

ULL X = 13331;
vector<ULL> h, x;

void Hash(string &s) {
	int n = s.length();
	//初始化 
	h[0] = s[0];
	x[0] = 1;
	//进位 abc = a*26^2 + b*26^1 + c*26^0
	for (int i = 1; i < n; i++) {
		h[i] = h[i-1]*X + s[i];
		x[i] = x[i-1]*X;
	}
}

ULL getHashCode(int left, int right) {
	if (!left) {
		return h[right];
	}
	//前缀和求子子串的哈希code 
//	"abcde"		right = 3 'd', left = 1 'b'   
//	 h[right] - h[left-1] = abcd - a = bcd   的哈希  
	ULL ans = h[right] - h[left-1] * x[right-left+1];
	return ans;
	
//	return left ? h[right] - h[left-1] * x[right-left+1] : h[right];
}

int main() {
	string s1;
	cin >> s1;
	
	h.resize(s1.length());
	x.resize(s1.length());
	
	Hash(s1);
	
	string s2;
	cin >> s2;
	
	ULL hash2 = 0;
	for (int i = 0; i < s2.length(); i++) {
		hash2 = hash2 * X + s2[i];
	}
	for (int i = 0; i < s1.length(); i++) {
		int start = i;
		int end = min(s1.length()-1,i+s2.length()-1);
		cout << getHashCode(start,end) << " ";
	}
	cout << endl;
	cout << hash2 << endl;
	return 0;
} 
