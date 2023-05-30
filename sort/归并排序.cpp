#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right);

void mergeSort(vector<int> &nums,int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = (left + right) >> 1;
	mergeSort(nums,left, mid);
	mergeSort(nums,mid+1,right);
	merge(nums,left,mid,right);
}

void merge(vector<int> &nums, int left, int mid, int right) {
	if (left >= right) {
		return;
	}
	
	int i = left, j = mid +1, k = 0;
	vector<int> array;
	while (i <= mid && j <= right) {
		if (nums[i] < nums[j]) {
			array.push_back(nums[i]);
			i++;
		} else if (nums[i] >= nums[j]) {
			array.push_back(nums[j]);
			j++;
		}
		k++;
	}
	
	while (i<=mid) {
		array.push_back(nums[i]);
		k++;
		i++;
	}
	while (j<=right) {
		array.push_back(nums[j]);
		k++; 
		j++;
	}
	for (int t=0; t<array.size(); t++){
		nums[left+t] = array[t];
	}
}

int main() {
	vector<int> nums = {3,2,1,7,5,6,4};
	mergeSort(nums,0,nums.size()-1);
	for (int &x : nums) {
		cout << x << " ";
	} 
	cout << endl;
	return 0;
}
