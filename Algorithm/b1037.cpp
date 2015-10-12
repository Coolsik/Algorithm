#include <iostream>
#include <algorithm>
using namespace std;
int arr[51];
int main(){
	int T;
	int N, temp;
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> arr[i];
	}
	sort(arr, arr + T);
	if (T % 2 == 0){
		N = arr[0] * arr[T - 1];
	}
	else{
		N = arr[T / 2] * arr[T / 2];
	}
	cout << N;
}