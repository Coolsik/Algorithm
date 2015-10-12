#include <iostream>

using namespace std;

void hanoi(int n,int here, int temp, int target) {
	if (n == 1) {
		cout << here << " -> " << target << endl;
	}
	else {
		hanoi(n - 1, here, target, temp);
		cout << here << " -> " << target << endl;
		hanoi(n - 1, temp, here, target);
	}
}

int main() {
	int n;
	cin >> n;
	hanoi(n, 1,2,3);
	return 0;
}