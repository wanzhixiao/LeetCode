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
                if ((mask >> ch) & 1) { // �� mask ���� ch����˵�� s �����ظ���ĸ���޷����ɿ��н�
                    mask = 0;
                    break;
                }
                mask |= 1 << ch; // �� ch ���� mask ��
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
            if ((mask & masks[pos]) == 0) { // mask �� masks[pos] �޹���Ԫ��
                backtrack(pos + 1, mask | masks[pos]);
            }
            backtrack(pos + 1, mask);
        };
        backtrack(0, 0);
        return ans;
    }


// ������ö�� 
private:
    int ans = 0;
public:
    int maxLength(vector<string>& arr) {
       
        // ����ÿ���ַ������ַ��ĳ��ִ��������Ƿ����ظ���û���ظ����mask�ӵ�mask������
        int n = arr.size();
        vector<int> masks;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (char ch : arr[i]) {
                ch -= 'a';
                if ((mask >> ch) & 1) { //arr[i]�ַ����д����ظ����ַ�
                    mask = 0;
                    break;
                }
                // ��ch ��ӵ�mask��
                mask |= (1 << ch);
            }
            if (mask) {
                masks.push_back(mask);
            }
        }
        int ans = 0;
        // dfs�ж�mask[i] & mask[pos] == 0, ѡ���߲�ѡnums[pos]
        function<void(int,int)> f = [&](int mask, int pos) {
            if (pos == masks.size()) {
                int numOnes = 0;
                while (mask) {
                    //ȡ�����ұߵ�1
                    long long x = mask & (-mask);
                    mask -= x;
                    numOnes++;
                }
                ans = max(ans, numOnes);
                return;
            }
            //��ѡ��pos��Ԫ��
            f(mask, pos+1);
            // ��ƴ�ӵ��ַ����͵�һ���ַ���û���ظ�Ԫ��
            if ((mask & masks[pos]) == 0) {
                //ѡ��pos��Ԫ��
                f(mask|masks[pos], pos+1);
            }
        };
        f(0,0);
        return ans;
    }  
    
public:
	// ���Ʒ��� 
    int maxLength(vector<string>& arr) {
       
        // ����ÿ���ַ������ַ��ĳ��ִ��������Ƿ����ظ���û���ظ����mask�ӵ�mask������
        int n = arr.size();

        //���ü���һ��0
        vector<int> masks{0};

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (char ch : arr[i]) {
                ch -= 'a';
                if ((mask >> ch) & 1) { //arr[i]�ַ����д����ظ����ַ�
                    mask = 0;
                    break;
                }
                // ��ch ��ӵ�mask��
                mask |= (1 << ch);
            }
            if (mask == 0) {
                continue;
            }

            for (int i = 0; i < masks.size(); i++) {
                if ((mask & masks[i]) == 0) {
                    // û�г�ͻ��mask | masks[i]���뵽mask������
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
	cout << mask << endl;			//  1 1 1 0;			//�������ң���1λ����2λ����3λ����1
	
	cout << (mask >> c) << endl; 	//ʣ��ԭ�������λ1   0001
	cout << (mask >> b) << endl; 	//ʣ�� 0011 
	cout << (mask >> a) << endl;
	
	int d = 8;
	cout << (d & (-d)) << endl;     // 8 
*/


int main() {
	
	return 0;
}
