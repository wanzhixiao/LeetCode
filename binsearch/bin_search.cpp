#include<iostream>
#include<vector>
using namespace std;

int bin_search(vector<int> indices, int target) {
    int low = 0, high = indices.size();
    while (low < high) {	//[) 
        int mid = (high - low) / 2 + low;
        if (indices[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;	
}

/*
1,2,3,4,6
target = 2;

left = 0, right = 5
mid = 2, indices[2] >= target,  right = mid = 2

left = 0, right = 2
mid = 1, indices[1] >= target, right = mid = 1

left = 0, right = 1
mid = 0, indices[0] < target, left = mid+1 = 1

return left (1)
*/

int bin_search2(vector<int> &indices, int target) {
	int low = -1, high = indices.size();
	while (low + 1 < high) {		//(left, right)
		int mid = low + (high - low)/2;
		if (indices[mid] >= target) {
			high = mid;
		} else {
			low = mid; 
		}
	}
	return high;
}

int main() {
	vector<int> indices = {1,2,3,4,6};
	int target = 5;
	cout << bin_search(indices, target) << endl;
	cout << bin_search2(indices, target) << endl;
	return 0;
}


