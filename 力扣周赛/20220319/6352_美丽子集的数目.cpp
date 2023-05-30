#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j<n; j++) {
                if (abs(nums[i]-nums[j]) != k) {
                    ans++;
                }
            }
        }
        return ans;
    }
    
    int beautifulSubsets2(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            int tar1 = cur + k;
            int tar2 = cur - k; 
            
            // ������ 
            int left = i+1, right = n-1;
            int mid = left;
//            while (left <= right) {
//                mid = left + (right-left)/2;
//                if (nums[mid] == tar1) {
//                    break;
//                } else if(nums[mid] < tar1) {
//                    left = mid + 1;
//                } else {
//                    right = mid - 1;
//                }
//            }
//            ans = ans + ((mid >= n) ? 0 : ((nums[mid] == tar1) ? (n-mid-1) : (n-i-1)));
//            cout << i << " " << nums[i] << " " <<  mid << " " << nums[mid] << " " << ans << endl;
            
            // ������ 
            left = 0, right = i-1;
            mid = left;
			while (left <= right) {
			    mid = left + (right-left)/2;
                if (nums[mid] == tar2) {
                    break;
                } else if(nums[mid] < tar2) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }	
			} 
            cout << tar2 << endl;
     		
     		
     		if (tar2 >= 0) {
     			cout << "ans1 =" << ans << endl;
     			ans = ans + ((nums[mid] == tar2) ? (i-1) : i);
     			cout << "ans2 = " << ans << endl;
     			cout << i << " " << nums[i] << " " <<  mid << " " << nums[mid] << " " << ans << endl;
			}
        }
        return ans;
    }
    
private: 
    int vis[1010];
    int mx = 0;
    int ans = 0;
public:
    int beautifulSubsets3(vector<int>& nums, int k) {
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
        }
        dfs(nums, k, 0);
        return ans-1;
    }

    void dfs(vector<int> &nums, int k, int pos) {
        if (pos == nums.size()) {
            ans += 1;
            return;
        }
        //��ѡ
        dfs (nums, k, pos+1);  
        // ѡ
        bool flag = true;
        cout << nums[pos] << " " << nums[pos] + k << " " << vis[nums[pos] + k] << " " << nums[pos] - k <<" " << vis[nums[pos] - k]<< endl;
       	//��֦ 
	    if (nums[pos] - k >=0 && vis[nums[pos]-k] != 0) {
            flag = false;
        }
        if (nums[pos]+k <= mx && vis[nums[pos]+k] != 0) {
            flag = false;
        }
        //����ѡ
        if (flag) {
            // ѡ nums[pos]
            cout << vis[nums[pos]-k] << " " << vis[nums[pos]] << " " << vis[nums[pos]+k] <<  " "<< pos <<  endl;
            vis[nums[pos]]++;
            cout <<  nums[pos] << " ѡ��" << endl;
            dfs(nums, k, pos+1);
            cout <<  nums[pos] << " ����" << endl;
            vis[nums[pos]]--;
        }
        
        /*
			6 8 0 4 0
			0 0 0 2
			6 ѡ��
			6 ����
			4 6 0 2 0
			0 0 0 1
			4 ѡ��
			6 8 0 4 1
			4 ����
			2 4 0 0 0
			0 0 0 0
			2 ѡ��
			6 8 0 4 0
			0 0 0 2
			6 ѡ��
			6 ����
			4 6 0 2 1
			2 ����
		*/
        
    }

/*
    2 4 6
    k = 2
                                        2             pos = 0
                                     -2/  \+2
                                      0    4             //��0��4��û����vis�г��ֹ�
                                2����ѡ
                                                      pos = 1
                                   4
                                -2/ \+2
                                2    6                // 2��vis�г��֣����4��ѡ
                                vis[4]--
                                                     pos = 2
                                6
                               / \


                        ""
                       /   \
  n-2                 ""     2
                     / \    / \
  n-1               ""  4  2   6
                   /  \
  n              ""   6
*/
};


int main() {
	vector<int> nums = {2,4,6};
	int k = 2;
	//[4,2,5,9,10,3] 1
	//[10,4,5,7,2,1] 3
	Solution solu;
	
	// pred: 17, truth: 23
	cout <<solu.beautifulSubsets3(nums, k) << endl;
	return 0;
}
