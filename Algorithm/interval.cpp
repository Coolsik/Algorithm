#include <iostream>

using namespace std;
int M, N;
int mx[101][101][2];
int arr[101];
int d[101][101];
int p[101][101][3];

void dfs(int x, int y) {
	if (x == 0 || y == 0) return;
	dfs(p[x][y][0], p[x][y][1]);
	cout << p[x][y][2] << " ";
}
int main() {
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= M; i++) {
		int min = arr[i];
		int max = arr[i];
		for (int j = i + 1; j <= M; j++) {
			if (arr[j] < min) min = arr[j];
			if (arr[j] > max)max = arr[j];
			mx[i][j][0] = min;
			mx[i][j][1] = max;
		}
	}

	for (int j = 1; j <= M/2; j++) {
		for (int i = 2; i <= M; i++) {
			//for (int k = i - 2; k >= (j - 1) * 2; k--) {
			for (int k = (j - 1) * 2; k <= i; k++) {
				if (d[i][j] < d[k][j - 1] + mx[k + 1][i][1] - mx[k + 1][i][0]) {
					if (i == 10 && j == 4) {
						int temp = 1;
					}
					d[i][j] = d[k][j - 1] + mx[k + 1][i][1] - mx[k + 1][i][0];
					p[i][j][0] = k;
					p[i][j][1] = j - 1;
					p[i][j][2] = i - k;
				}
			}
		}
	}
	int max = 0;
	int x, y;
	for (int i = 0; i <= M / 2;  i++) {
		if (max < d[M][i]) {
			max = d[M][i];
			x = M;
			y = i;
		}
	}
	cout << max << endl << y << endl;
	dfs(x, y);

	return 0;
}