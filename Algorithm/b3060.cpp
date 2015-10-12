#include <iostream>
using namespace std;

int main(){
	int testcase;
	cin >> testcase;
	while (testcase-- > 0) {
		int sum=0;
		int food;
		cin >> food;
		for (int i = 0; i < 6; i++) {
			int temp;
			cin >> temp;
			sum += temp;
		}
		int i = 1;
		while (sum <= food) {
			sum = sum * 4;
			i++;
		}
		cout << i << endl;
	}


	return 0;
}