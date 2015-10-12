#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int arr[5];
	int average = 0;
	for (int i = 0; i < 5; i++){
		cin >> arr[i];
		average += arr[i];
	}
	average = average / 5;
	
	sort(arr, arr + 5);
	cout << average << endl;

	cout << arr[2] << endl;
}