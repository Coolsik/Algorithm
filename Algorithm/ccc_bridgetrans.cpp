#include <iostream>
using namespace std;

int arr[100005];

int main() {
	int W, N;
	int sum = 0;
	cin >> W;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		sum += arr[i];
		if (i > 3) {
			sum -= arr[i - 4];
		}
		if (W < sum) {
			cout << i;
			break;
		}
		if (i == N - 1) {
			cout << N;
		}
	}



	return 0;
}