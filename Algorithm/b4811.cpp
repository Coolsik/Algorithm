#include <iostream>
using namespace std;

long long arr[32] = { 1,1 };

int main() {
	for (int i = 2; i < 31; i++) {
		int temp = 0;
		for (int j = i - 1; j >= 0; j--) {
			arr[i] += arr[j] * arr[temp++];
		}
	}

	while(true){
		int n;
		cin >> n;
		if (n == 0) { break; }
		cout << arr[n] << endl;
	}
	
}