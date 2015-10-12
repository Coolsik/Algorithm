#include <iostream>
#include <algorithm>
using namespace std;


int main(){

	int N, P;
	int arr[100];
	int save_first=0, save_last=0;
	int count = 0;
	cin >> N >> P;

	arr[0] = N;

	for (int i = 1; i < 100; i++) {
		arr[i] = (arr[i - 1] * N) % P;
		
		if (save_first){
			if (arr[++save_first] == arr[i]){
				count++;
				if (save_first == save_last){
					break;
				}
				continue;
			}
		}

		for (int j = 0; j < i; j++){
			if (arr[i] == arr[j]){
				save_first = j;
				save_last = i;
				break;
			}
		}
		
	}

	cout << count << endl;

	return 0;
}