#include <iostream>

using namespace std;

int arr[3][1000001];
int arr2[1000001];
int main() {
	int a, b, d, N;

	cin >> a >> b >> d >> N;
	arr[0][0] = 1;
	/*for (int i = 1; i <= N; i++) {
		if (i >= a) {
			arr[0][i] = arr[0][i - a] + arr[1][i - a];
		}
		if (b - a <= i) {
			arr[1][i] = arr[0][i - (b - a)];
		}
		if (d - b <= i) {
			arr[2][i] = arr[1][i-(d - b)] - arr[2][i-(d - b)];
		}
	}

	cout << arr[0][N-1] + arr[1][N-1] + arr[2][N-1];
	*/
	arr2[0] = 1;
	for (int i = 1; i <= N; i++) {
		arr2[i] = arr2[i - 1];
		if (i >= a) {
			arr2[i] += arr2[i - a];
		}
		if (i >= b) {
			arr2[i] -= arr2[i - b];
		}
		arr2[i] = arr2[i] % 1000;
	}
	cout << (arr2[N] - arr2[N - d]+2000)%1000;

	return 0;
}