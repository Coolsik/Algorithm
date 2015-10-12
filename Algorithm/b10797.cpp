#include <iostream>

using namespace std;

int main() {
	int n, cnt=0;
	cin >> n;

	for (int i = 0; i < 5; i++) {
		int c;
		cin >> c;
		if (c == n) cnt++;
	}

	cout << cnt << endl;
	return 0;
}