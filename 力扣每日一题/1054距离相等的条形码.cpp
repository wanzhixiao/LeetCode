
/*
���������������е����֣�ʹ�����ڵ������������ظ�������������е��������� 
���룺barcodes = [1,1,1,2,2,2]
�����[2,1,2,1,2,1]

1.����
2.����
3. �������� 
*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    	// ���� 
        unordered_map<int,int> mp;
        for (int x:barcodes) {
            mp[x] += 1;
        }
        vector<pair<int,int>> vec;
        auto it = mp.begin();
        while (it != mp.end()) {
            vec.push_back({it->first, it->second});
            ++it;
        }
        // ���� 
        sort(vec.begin(),vec.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.second < b.second;
        });
        // �������� 
        vector<int> num;
        for (int i = 0, n = vec.size(); i < n; i++) {
            int val = vec[i].first;
            int count = vec[i].second;
            for (int j = 0; j < count; j++) {
                num.push_back(val);
            }
        }
        vector<int> ans;
        int n = num.size();
        int i = 0, mid = n/2, j = n/2;
        int a = 0;
        // cout << n << endl;
        while (i < mid && j < n) {
            if (a%2==1) {
                ans.push_back(num[i]);
                i+=1;
            } else {
                ans.push_back(num[j]);
                j+=1;
            }
            a += 1;
        }
        while (i < mid) {
            ans.push_back(num[i++]);
        }
        while (j < n) {
            ans.push_back(num[j++]);
        }
        return ans;
    }
};
