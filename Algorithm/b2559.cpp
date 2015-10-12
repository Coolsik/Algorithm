#include <iostream>
#include <cstdio>

using namespace std;
int arr[100001];
int main() {

	int N, K, sum = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (i < K) {
			sum += arr[i];
		}
	}
	int max = sum;

	for (int i = K; i < N; i++) {
		sum -= arr[i - K];
		sum += arr[i];
		if (sum > max) {
			max = sum;
		}
	}
	
	cout << max << endl;

	return 0;
}