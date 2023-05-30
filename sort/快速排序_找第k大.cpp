#include<iostream>
#include<vector>
using namespace std;
/*
6,3,1,5,4,7,4,4,1,2
k = 5
ans = 4

0 8 9
0 0 7
1 3 7
4 4 7
5 7 7
5 5 6
4
*/
int quickSort(vector<int> &nums, int left, int right, int k);
void swap(vector<int> &nums, int i, int j);

int findK(vector<int> &nums, int k) {
	int n = nums.size();
	return quickSort(nums, 0, n-1, n-k);
}

int quickSort(vector<int> &nums, int left, int right, int k) {
	if (left >= right) {
		return nums[k];
	}
	int pivot = left;
	int i = left, j = right;
	while (i < j) {
		while (i < j && nums[j] >= nums[pivot]) {
			--j;
		} 
		while (i < j && nums[i] <= nums[pivot]) {
			++i;
		}
		if (i < j) {
			swap(nums, i, j);
		}
	}
	swap(nums, i, pivot);
	cout << left << " " << i << " " << right << endl; 
	if (k == i) {
		return nums[i];
	}
	else if (i < k) {			//第k大在i的右侧 
		return quickSort(nums, i+1, right, k);
	} 
	else {						//第k大在i的左侧 
		return quickSort(nums, left, i-1, k);
	}	
}

void swap(vector<int> &nums, int i, int j) {
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}


//力扣官方题解 
class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        int target = n - k;
        int left = 0, right = n - 1;
        
        while (true) {
            int pivot = partition(arr, left, right);
            if (target == pivot) {
                // cout << arr[pivot] << endl;
                // return vector<int>(arr.begin(), arr.begin()+k);
                return arr[pivot];
            } else if(target > pivot) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        return {};
    }

    int partition(vector<int> &nums, int left, int right) {
        int randomIndex = left + random()%(right-left+1);
        // int randomIndex = left;
        swap(nums, randomIndex, left);
        int i = left + 1;
        int j = right;
        int x = nums[left];

        while (true) {
            while (i <= j && nums[i] < x) {
                ++i;
            }
            while (i <= j && nums[j] > x) {
                j--;
            }
            if (i >= j) {
                break;
            }
            swap(nums, i, j);
            i++;
            j--;
        }
        swap(nums, left, j);
        return j;
    }

    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};


int main() {
  vector<int> nums = {6,3,1,5,4,7,4,4,1,2};

  
  int k = 5;
  cout << findK(nums, k)  << endl;
  
  for (int i = 0; i < nums.size(); i++) {
  	cout << nums[i] << " "; 
  }
  cout << endl;
  return 0;
}


//6,3,1,5,4,7,4,4,1,2

/*
n  logn 

1 1 2 3 4 4 5 6 7
k = 3

left ... i-1  i  i+1..right

right - i = k
*/ 
