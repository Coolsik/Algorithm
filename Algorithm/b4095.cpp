#include <iostream>
#include <cstdio>
using namespace std;

int map[1001][1001];
//int d[1001][1001];

int min(int i, int j) {
	int temp = map[i - 1][j - 1];
	if (temp > map[i - 1][j]) temp = map[i - 1][j];
	if (temp > map[i][j - 1]) temp = map[i][j - 1];

	return temp;
}

int main() {
	int N, M;
	cin >> N >> M;
	while (N != 0 && M != 0) {
		int max = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				int temp;
				scanf("%d", &temp);
				if (temp == 0) {
					map[i][j] = 0;
				}
				else {
					map[i][j] = min(i, j) + 1;
				}
				if (map[i][j] > max) {
					max = map[i][j];
				}
			}
		}
		cout << max << endl;
		cin >> N >> M;
	}

	return 0;
}