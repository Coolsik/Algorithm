#include <iostream>

using namespace std;

int main(){
	int N;
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N-1; i++){
		int temp;
		cin >> temp;
		sum += temp - 1;
	}

	int temp;
	cin >> temp;
	sum += temp;

	cout << sum << endl;


}