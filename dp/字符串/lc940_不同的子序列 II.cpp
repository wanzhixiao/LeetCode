#include<iostream>
#include<string>
#include<string.h>
#include<vector> 
using namespace std; 


/*
dp[i]表示s[0...i]中不同子序列的数目 

如果s[i]没有在s[0...i-1]中出现过 
abc, s[i] = c;  
dp[i] = 2*dp[i-1]

如果s[i]在s[0...i-1]中出现过  
dp[i] = 2*dp[i-1] - dp[cnt[s[i]]-1];   dp[cnt[s[i]]--1]表示 s[i]上一次出现的字符位置为cnt[s[i]]， -1取上一次的前一个字符

acbc		s[i] = c;  ac1, ac2 形成重复字符，因此减去cnt[c] - 1 

cnt[s[i]] = i 表示字符s[i]出现的位置为i 
*/

class Solution {
private:
	const long long mod = 1e9+7;
public:
	
    int distinctSubseqII(string s) {
        int cnt[27];
        memset(cnt,-1,sizeof(cnt));
        int n = s.length();
        if (n == 1) {
            return 1;
        }
        vector<long long> dp(n+1,0);
        dp[0] = 1;

        for (int i = 1; i<= n; i++) {
            if (cnt[s[i-1]-'a'] == -1) {
                dp[i] = 2*dp[i-1];
            } else {
                dp[i] = 2*dp[i-1] - dp[cnt[s[i-1]-'a']-1];   
                //caba,,  ca1 , ca2 
				//减去上一个s[i]签名字符所构成子序列个数，因为加上s[i]构成了与上一个s[i]相同的子序列
            }
            
            
          	//以下为细节的处理 
          	//负数小于0需要加上mod 
            if (dp[i] < 0) {
                dp[i] = dp[i] + mod;
            }
          	if (dp[i] > mod) {
          		dp[i] %= mod;	
			}
            cnt[s[i-1]-'a'] = i;                //为什么是等于i??
        }

        return dp[n]-1;
    }
};


int main() {
	Solution solu;
	string s = "yezruvnatuipjeohsymapyxgfeczkevoxipckunlqjauvllfpwezhlzpbkfqazhexabomnlxkmoufneninbxxguuktvupmpfspwxiouwlfalexmluwcsbeqrzkivrphtpcoxqsueuxsalopbsgkzaibkpfmsztkwommkvgjjdvvggnvtlwrllcafhfocprnrzfoyehqhrvhpbbpxpsvomdpmksojckgkgkycoynbldkbnrlujegxotgmeyknpmpgajbgwmfftuphfzrywarqkpkfnwtzgdkdcyvwkqawwyjuskpvqomfchnlojmeltlwvqomucipcwxkgsktjxpwhujaexhejeflpctmjpuguslmzvpykbldcbxqnwgycpfccgeychkxfopixijeypzyryglutxweffyrqtkfrqlhtjweodttchnugybsmacpgperznunffrdavyqgilqlplebbkdopyyxcoamfxhpmdyrtutfxsejkwiyvdwggyhgsdpfxpznrccwdupfzlubkhppmasdbqfzttbhfismeamenyukzqoupbzxashwuvfkmkosgevcjnlpfgxgzumktsexvwhylhiupwfwyxotwnxodttsrifgzkkedurayjgxlhxjzlxikcgerptpufocymfrkyayvklsalgmtifpiczwnozmgowzchjiop";
	cout << solu.distinctSubseqII(s) << endl;
	return 0;
}
