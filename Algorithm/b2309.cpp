#include <iostream>
#include <algorithm>

using namespace std;

int temp[7];
int input[9];

bool isAnswer(int n1, int n2){
	int j = 0;
	int sum = 0;
	for (int i = 0; i < 9; i++){
		if (i == n1 || i == n2){
			continue;
		}
		temp[j++] = input[i];
		sum += input[i];
	}
	
	return sum == 100;
}

int main(){

	for (int i = 0; i < 9; i++){
		cin >> input[i];
	}

	for (int i = 0; i < 8; i++){
		for (int j = i + 1; j < 9; j++){
			if (isAnswer(i, j)){
				sort(temp, temp + 7);
				i = 9;
				break;
			}
		}
	}

	for (int i = 0; i < 7; i++){
		cout << temp[i] << endl;
	}

	return 0;
}