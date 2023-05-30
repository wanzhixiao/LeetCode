#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	 
	int m, n, w;
	cin >> m >> n;
	vector<int> weight;
	for (int i = 0; i < n; i++) {
		cin >> w;
		weight.push_back(w);
	} 
	sort(weight.begin(), weight.end(),[&](int a, int b){return a>b;
	});
	int i = 0, j = n-1;
	int ans = 0;
	
	while (i <= j) {
		int lw = weight[i], rw = weight[j];
		if (lw + rw <= m) {
			ans += 1;
			i++;
			j--;
		} else {
			ans += 1;
			i++;
		} 
	}
	if (i == j) {
		ans += 1;
	}
	cout << ans << endl;
	return 0;
} 
