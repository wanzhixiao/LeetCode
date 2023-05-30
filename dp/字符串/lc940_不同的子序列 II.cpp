#include<iostream>
#include<string>
#include<string.h>
#include<vector> 
using namespace std; 


/*
dp[i]��ʾs[0...i]�в�ͬ�����е���Ŀ 

���s[i]û����s[0...i-1]�г��ֹ� 
abc, s[i] = c;  
dp[i] = 2*dp[i-1]

���s[i]��s[0...i-1]�г��ֹ�  
dp[i] = 2*dp[i-1] - dp[cnt[s[i]]-1];   dp[cnt[s[i]]--1]��ʾ s[i]��һ�γ��ֵ��ַ�λ��Ϊcnt[s[i]]�� -1ȡ��һ�ε�ǰһ���ַ�

acbc		s[i] = c;  ac1, ac2 �γ��ظ��ַ�����˼�ȥcnt[c] - 1 

cnt[s[i]] = i ��ʾ�ַ�s[i]���ֵ�λ��Ϊi 
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
				//��ȥ��һ��s[i]ǩ���ַ������������и�������Ϊ����s[i]����������һ��s[i]��ͬ��������
            }
            
            
          	//����Ϊϸ�ڵĴ��� 
          	//����С��0��Ҫ����mod 
            if (dp[i] < 0) {
                dp[i] = dp[i] + mod;
            }
          	if (dp[i] > mod) {
          		dp[i] %= mod;	
			}
            cnt[s[i-1]-'a'] = i;                //Ϊʲô�ǵ���i??
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
