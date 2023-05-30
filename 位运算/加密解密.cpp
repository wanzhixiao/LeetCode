#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main() {
	//加密解密程序	
	string s = "i m a chinese!";	
	char key = 'b';
	string out = "";
	
	//加密 
	for (int i = 0 ; i < s.size(); i++) {
		out += s[i]^key;
	}
	cout << out << endl;
	
	char *p = new char[out.size()]; 
	for (int i = 0; i < out.size(); i++) {
		*(p+i) = out[i];
	}
	
	FILE *fp = fopen("file.txt","w");
	fwrite(p,out.size(),1,fp);
	fclose(fp);
	
	//解密 
	string dencrpt = "";
	for (int i = 0; i < out.size(); i++) {
		dencrpt += out[i]^key;
	}
	cout << dencrpt << endl;
	return 0;
} 

//https://blog.csdn.net/weixin_46141936/article/details/120899953
