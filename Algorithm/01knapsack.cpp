#include <iostream>

using namespace std;
int w, n;
int arr[102][2];
int d[101][10001];
int max(int a, int b) { return a > b?a:b; }
int main() {
	cin >> w >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			d[i][j] = d[i - 1][j];
			if (j - arr[i][0] >= 0) {
				d[i][j] = max(d[i-1][j - arr[i][0]] + arr[i][1], d[i-1][j]);
			}
		}
	}

	cout << d[n][w];
	return 0;
}