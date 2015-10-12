#include <iostream>
#include <algorithm>
using namespace std;
int N, M;

typedef struct milk {
	int P;
	int A;
}milk;

milk arr[5001];

bool cmp(milk a, milk b) {
	return a.P < b.P;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> arr[i].P >> arr[i].A;
	}

	sort(arr, arr + M, cmp);

	int result = 0;
	int i = 0;
	while (N > 0) {
		if (arr[i].A < N) {
			result += arr[i].P*arr[i].A;
			N -= arr[i].A;
			i++;
		}
		else {
			result += arr[i].P*N;
			N = 0;
		}
	}

	cout << result;

	return 0;
}