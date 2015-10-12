#include <iostream>
using namespace std;

long long arr[20] = { 1,1 };

int main() {
	for (int i = 2; i < 20; i++) {
		int temp = 0;
		for (int j = i - 1; j >= 0; j--) {
			arr[i] += arr[j] * arr[temp++];
		}
	}

	int n;
	cin >> n;
	cout << arr[n] << endl;

}