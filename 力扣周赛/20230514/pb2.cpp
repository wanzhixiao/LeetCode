#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int s1 = forceEnum(derived, n, 0);
        int s2 = forceEnum(derived, n, 1);
        cout << endl;
        cout << s1 << " " << s2 << endl;
        return s1 || s2;
    }
    
    bool forceEnum(vector<int>& derived, int n, int prev) {
        bool flag=false;
        vector<int> original(n,0);
       	original[0] = prev;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++) {		//Ã¶¾Ùi+1Î» 
                if (i < n-1) {
                    if (derived[i] == (j^original[i])) {  //derived[i] == original[i]^original[i+1] 
//                        prev = j;
                        original[i+1] = j;
                        flag = true;
                        break;
                    } else {
                    	flag = false;
					}
                } else if (i == n-1) {
                	cout << "ith--";
           			for (int x : original)  {
           				cout << x << " -- ";
					}
					cout << endl;
                    if (derived[i] == (original[i]^original[0])) {
//                        prev = j;
                        flag = true;
                        break;
                    } else {
                    	flag = false;
					}
                }

            }
//            original[i+1] = prev;
//            if (!flag) {
//                return false;
//            }
        }
        return flag;
    }
};

/*
class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        a = 0
        for x in derived:
            a ^= x
        return a == 0

    a^a = 0
    0 ^ b = 1

    derived[i] = original[i]^orginal[i+1]
    derived[i]^original[i] = original[i+1]

    a = derived
    b = orginal

    a[i] = b[i] ^ b[i+1]
    a[i] ^ b[i] = b[i+1]
    b[i+1] = a[i] ^ b[i]

    b[1] = a[0] ^ b[0]
    b[2] = a[1] ^ b[1] = a[1] ^ a[0] ^ b[0]
    b[3] = a[2] ^ b[2] = a[2] ^ a[1] ^ a[0] ^ b[0]

    b[3] ^ b[0] = a[2] ^ a[1] ^ a[0]
    a[3] = b[3] ^ a[0] = a[2] ^ a[1] ^ a[0]
    0 = a[2] ^ a[1] ^ a[0] ^ a[3]



    b[0] ^ b[1]
    b[1] ^ b[2]
    b[2] ^ b[3]
    b[3] ^ b[0]
'''
*/

int main() {
	Solution s;
	vector<int> derived = {1,0};
	cout << s.doesValidArrayExist(derived) << endl;
	return 0;
}
