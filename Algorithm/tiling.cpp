#include <iostream>

using namespace std;
unsigned long long int arr[251];
int main() {
	int N;
	cin >> N;

	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] * 2;
	}
	cout << arr[N];

	return 0;
}