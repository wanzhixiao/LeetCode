#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int maxNumOfMarkedIndices(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (nums[i]==0) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (i == j || nums[j] == 0) {
                continue;
            }
            if (2*nums[i] <= nums[j]) {
            	cout << nums[i] << " " << nums[j] << endl;
                nums[i] = 0;
                nums[j] = 0;
                ans += 2;
                break;
            }
        }
    }
    return ans;
}


bool binsearch(vector<int> &nums, int left, int right) {
	int n = nums.size();
//	while (left + 1 < right) {
//		int mid = left + (right - left >> 1);
//		if (2*nums[mid] <= nums[n-1]) {
//			return true;
//		}
//		else {
//			right = mid;
//		}
//	}

	for (int i = left; i < right; i++) {
		if (2*nums[i] > nums[n-1]) {
			return false;
		} 
	}
	return true;
}

int maxNumOfMarkedIndices2(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) {
    	cout << nums[i] << " "; 
        mp[nums[i]] = 0;
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
    	cout << nums[i] << endl;
   		if (nums[i] == 0) {
   			continue;	
		}
		int left = i, right = n;
		
		while (left + 1 < right) {
			int mid = left + (right-left >> 1);
			if (2*nums[i] <= nums[mid]) {
				right = mid;
				
				//�鿴 i+1 ��mid-1�Ƿ��� nums[k] <= nums[n-1] ? 
				
				if (binsearch(nums,i+1,mid)) {
					break;
				}
				
//				if (mid >= 1 && 2*nums[mid-1] <= nums[n-1]) {
//					break;
//				} 

			} else {
				left = mid;
			}
		}
	    if (right < n && mp[right] == 0) {
            mp[right] = 1;
            ans += 2;
	        cout << i << " -- " << nums[i] << " " << right << " " << nums[right] << endl;
	    }
	    cout << i << " " << nums[i] << " " << right << " " << nums[right] << endl;

    }
    return ans;
}



////////////////////////////////////////////////////////////////////////////////////////// �ο���� 
/*
    2 3 | 4 5 ǰ�����Ƿ��ܺͺ��������
    1 2 3| 4 5
    2 4 | 5 9


    ö��2 4
    left = 0, right = 4/2+1 = 3     //������

    ��2��4�Ƿ��ܺ��ұߵ���ƥ�䣬�ҵ�����ܹ�ƥ�����������left
    
    n = 4
    k �� ��0, n/2+1��
    for (int i = 0; i < k; i++) {
        if (2*nums[i] > nums[n-k+i]) {
            return false;
        }
    }
    
    ���������ֲ���
    ��������ȥ��̽����ƥ���������Ͻ�
	
	������ i�ʣ�0��n+1/2��,  
	2 * nums[i] <= nums[n-k+i]			
	n-k+i���ұߵ�ĳ������ ����2,4,5,9
	n = 4, 
	i ��(0,2)�� k = (left+right)/2;
	
	�������е�i�� ��� 2*nums[i] <= nums[n-k+i] 		n-k+i����[2��4��
	����left = mid
	 ���� right = mid 
	 
	 
	����Ĺؼ����뵽  2 4 | 5 9 �������С���Ҳ�������������ƥ���������������±��Ƕ��٣� 
*/



class Solution {
public:
	// ���ֲ��� 
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n/2 + 1;

        while (left + 1 < right) {
            int mid = left + (right-left)/2;
             if (check(nums,mid)) {
                 left = mid;
             } else {
                 right = mid;
             }
//            (check(nums, mid) ? left : right) = mid;
        }
        return 2*left;
    }
	
    bool check(vector<int> &nums, int k) {
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            if (2*nums[i] > nums[n-k+i]) {
            	return false;
			}
        }
        return true;
    }
	
	// ˫ָ��ⷨ 
	int maxNumOfMarkedIndices2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = (n+1)/2;
		
		//2 4 | 5 9
		// i = 0 , right = 4/2 + 1 = 3
		int i = 0;		
		for (int j = right; j < n; j++ ) {      //ö���ұߵ���
			if (2*nums[i] <= nums[j]) {         //����Ƿ����Ҳ�ƥ�䣬�����С����ƥ���Ҳ���С����
				i++;
			}
		} 
		return i*2;
    }
};
 


int main() {
//	vector<int> nums = {7,6,8};			//7,6,8 //3,5,2,4
//	vector<int> nums = {1,78,27,48,14,86,79,68,77,20,57,21,18,67,5,51,70,85,47,56,22,79,41,8,39,81,59,74,14,45,49,15,10,28,16,77,22,65,8,36,79,94,44,80,72,8,96,78,39,92,69,55,9,44,26,76,40,77,16,69,40,64,12,48,66,7,59,10};
	vector<int> nums = {1,2,3,4,5,6};
	
	Solution solu;
	
	int ans = solu.maxNumOfMarkedIndices2(nums);
	cout << ans << endl;
	
	return 0;
}
