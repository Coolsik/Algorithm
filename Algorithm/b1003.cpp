#include <iostream>

using namespace std;
int zero[41] = { 1, 0, };
int one[41] = { 0, 1 };
int main(){
	for (int i = 2; i < 41; i++){
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	int testcase;
	cin >> testcase;

	while (testcase-- > 0){
		int index;
		cin >> index;
		cout << zero[index] << " " << one[index] << endl;

	}

	return 0;
}