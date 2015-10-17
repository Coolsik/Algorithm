#include <iostream>
using namespace std;
int arr[101][2];
int main() {
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0];
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (arr[j][0] <= arr[i][0] && arr[j][1] >= arr[i][1]) {
				arr[i][1] = arr[j][1] + 1;
				if (max < arr[i][1]) max = arr[i][1];
			}
		}
	}

	cout << max;

	return 0;
}