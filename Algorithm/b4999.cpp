#include <iostream>
#include <string>
using namespace std;

int main() {
	string a1, a2;

	cin >> a1 >> a2;

	if (a1.length() >= a2.length()) {
		cout << "go" << endl;
	}
	else {
		cout << "no" << endl;
	}

}