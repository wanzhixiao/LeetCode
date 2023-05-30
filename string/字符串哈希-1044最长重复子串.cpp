const int maxn = 1e5 + 50;
const int base = 131; //or base = 13331
using ULL = unsigned long long;
ULL h[maxn],f[maxn];

ULL get(int l,int r){
    if(l == 0) return h[r];
    else return h[r] - h[l - 1] * f[r - l + 1];
}
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        //预处理哈希值
        f[0] = 1;
        for(int i = 0; i < n; i++){
            if(i == 0) h[i] = s[i];
            else{
                h[i] = h[i - 1] * base + s[i];
                f[i] = f[i - 1] * base;
            }
        }
        string ans;
        int l = 0, r = n - 1,mx = 0;
        //二分重复子串的最大长度
        while(l < r){
            int mid = l + r + 1  >> 1;
            auto cur = check(mid,s);
            if(cur.size() > mx){
                mx = max(mx,mid);
                ans = cur;
                l = mid;
            }
            else r = mid - 1;
        }
        return ans;

    }
    string check(int mid,const string& s){
        unordered_map<ULL,bool> mp;
        string cur;
        for(int i = 0;i < s.size(); i++){
            if(i + mid - 1 < s.size()){
                ULL key = get(i,i + mid - 1);
                if(mp.count(key)) {
                    cur = s.substr(i,mid);
                    break;
                }
                mp[key] = true;
            }
        }
        return cur;
    }
};

