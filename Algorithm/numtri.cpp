#include <iostream>
#include <string.h>
using namespace std;
int N;
int a[1001][1001], d[1001][1001];

int max(int a, int b) {
	return a > b ? a : b;
}

int func(int i, int j) {
	int &ret = d[i][j];
	if (i == N) return 0;

	if (ret == -1) {
		ret = max(func(i + 1, j), func(i + 1, j + 1)) + a[i][j];
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	memset(d, -1, sizeof(d));

	cout << func(0, 0);


	return 0;
}