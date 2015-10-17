#include <iostream>

using namespace std;
int M, N;
int mx[101][101][2];
int arr[101];
int d[101][101];
int main() {
	cin >> M >> N;
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

	for (int j = 1; j <= N; j++) {
		for (int i = 2; i <= M; i++) {
			for (int k = i - 2; k >= (j - 1) * 2; k--) {
				if (d[i][j] < d[k][j - 1] + mx[k+1][i][1] - mx[k+1][i][0]) {
					d[i][j] = d[k][j - 1] + mx[k+1][i][1] - mx[k+1][i][0];
				}
			}
		}
	}

	cout << d[M][N];
	return 0;
}