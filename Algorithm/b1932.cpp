#include <iostream>
#include <cstring>
using namespace std;

int map[501][501];
int d[501][501];
int N;

int max(int a, int b) {
	return a > b ? a : b;
}

int func(int i, int j) {
	int &ret = d[i][j];
	if (i == N - 1) return map[i][j];	// 扁历 : i, j 啊 盖 关老版快.
	if (d[i][j] == -1) {
		ret = max(func(i + 1, j), func(i + 1, j + 1));
	}
	return ret+map[i][j];
}

int main() {
	cin >> N;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> map[i][j];
		}
	}
	
	cout << func(0, 0) << endl;

	return 0;
}
