#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	int size;
	int arr[11];
	string num;
	cin >> num;
	size = num.size();
	for (int i = 0; i < size; i++){
		arr[i] = num[i] - 48;
	}

	sort(arr, arr + size, greater<int>());

	for (int i = 0; i < size; i++){
		cout << arr[i];
	}

	return 0;
}