#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution6310 {
private:
    int mod = 1e9+7;
    int memo[52][1010];
    int f[1010]; 
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        // f[i][v]��ʾǰi����Ʒǡ�÷���һ������Ϊv�ı��������Ȩֵ
        int n = types.size();
        vector<vector<int>> f(n+1, vector<int>(target+1, 0)); 
        f[0][0] = 1;
        
        for (int i = 0; i < n; i++) {
        	int count = types[i][0];
        	int mark = types[i][1];
        	
        	for (int j = 0; j <= target; j++) {
        		//ÿ��Ŷ��ٸ� , ��i����Ʒ����j/mark��,  min(count, j/mark) 	
        		int res = 0;
        		for (int k = 0; k <= min(count, j/mark); k++) {
        			res += f[i][j-k*mark];
				}
				f[i+1][j] = res%mod;
					
			}
		}
		return f[n][target];
    }
    
    // ��ȫ��������̬�滮 
	int waysToReachTarget2(int target, vector<vector<int>>& types) {
        int n = types.size();
        memset(f, 0, sizeof(f));
        f[0]= 1;
        
        for (int i = 0; i < n; i++) {
            int count = types[i][0];
            int mark = types[i][1];
            for (int j = target; j >= 0; j--) {
                //������Ϊj����Ʒi�ܷŶ��ٸ�
                int res = 0;
                for (int k = 0; k <= min(count, j/mark); k++) {
			        res = (res%mod + f[j-k*mark]%mod)%mod;
                }
                f[j] = res%mod;
            }
        }
        return f[target];                
    }
    
	
	// ���仯���� 
    int waysToReachTarget3(int target, vector<vector<int>>& types) {
        int n = types.size();
        memset(memo, -1, sizeof(memo));
        return dfs(types, n-1, target);
    }
    
    int dfs(vector<vector<int>>& types, int i, int j) {
        if (i < 0) {
            return j == 0 ? 1 : 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int count = types[i][0], mark = types[i][1];
        int res = 0;
        for (int k = 0; k <= min(count, j/mark); k++) {
            res = (res % mod + dfs(types , i-1 , j - k*mark)%mod)%mod;
        }
        memo[i][j] = res;
        return res;
    } 
};

class Solution6309 {
private:
    int mod = 1e9 + 7;
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        vector<long long> product(n,1);
        product[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            product[i] = ((product[i-1])%mod * (nums[i]%mod))%mod;
            // cout << product[i] << endl;
        }
        for (int i = 0; i < n-1; i++) {
            int leftproduct = product[i];
            int rightproduct = product[n-1]/product[i];
            int gd = gcd(leftproduct, rightproduct);
            cout <<leftproduct << " " << rightproduct  << " " << gd << " " << endl;
            
            if (gd == 1) {
                    return i;
            }
        }
        return -1;
    }
    int gcd(int a, int b) {
        while (b != 0) {
            int d = a%b;
            a = b;
            b = d;
        }
        return a;
    }
};
int main() {
	Solution6310 solu;
	
	int target = 6;
	
	vector<vector<int>> types = {{6,1},{3,2},{2,3}};
	
	cout << solu.waysToReachTarget2(target, types) << endl;
	 
	return 0;
} 
