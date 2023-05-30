#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

vector<int> sampling(int N, int K) {
	srand(time(NULL));
	if (K < 1 || N < 1 || N < K) {
		return {};
	}
	vector<int> bag(K+1);
	for (int i = 1; i <= K; i++) {
		bag[i] = i;
	}
	for (int i = K+1; i <= N; i++) {
		int rnd = rand() % i + 1;
		if (rnd <= K) {
			int rnd2 = rand() % K + 1;
			bag[rnd2] = i;
		}
	}
	return bag;
}

int main() {
	vector<int> res = sampling(100, 10);
	for (auto e : res) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
