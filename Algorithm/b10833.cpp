#include <iostream>

using namespace std;

int main() {
	int testcase, student, apple;
	int sum = 0;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> student >> apple;
		sum += apple%student;
	}

	cout << sum << endl;

	return 0;
}