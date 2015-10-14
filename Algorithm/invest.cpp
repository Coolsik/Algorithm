#include <iostream>

using namespace std;

int arr[301][21];
int d[301][21];
int p[301][21];
int M, N;
void bt(int m, int n) {
	if (n == 0) { return; }
	bt(m - p[m][n], n - 1);
	cout << p[m][n] << " ";
}

int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (j == 1) {
				d[i][j] = arr[i][j];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k <= j; k++) {
				if (d[j][i] < d[k][i - 1] + arr[j - k][i]) {
					d[j][i] = d[k][i - 1] + arr[j - k][i];
					p[j][i] = j-k;
				}
			}
		}
	}
	cout << d[M][N] << endl;
	bt(M, N);
	  
	return 0;
}