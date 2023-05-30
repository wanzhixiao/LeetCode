#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	//��ʱ�� ������λ ÿ��*2 
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        unsigned int a = 1;
        while (a < n) {
            a = a<<1;
            if (a == n) {
                return true;
            }
        }
        return n>1 ? false : true;
    }
    
    //lowbit n&(-n) 
	// 8 ԭ�� 1000, ���� 0111, -8���� = ����+1 = 0111+0001 = 1000 
	bool isPowerOfTwo2(int n) {
		return n > 0 ? n & (-n) == n : false;
	}
};

int main() {
	int n = -16;
	Solution solu;
	cout << solu.isPowerOfTwo2(n) << endl;
	return 0;
}
