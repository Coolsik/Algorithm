#include <iostream>

using namespace std;
int arr[500500];
int main(){
	int count = 0;
	int cnt = 0;
	int A, B;
	for (int i = 1; i < 1001; i++){
		for (int j = 0; j < i; j++){
			arr[cnt++] = i;
		}
	}
	cin >> A >> B;

	for (int i = A - 1; i < B; i++){
		count += arr[i];
	}



	cout << count;
}