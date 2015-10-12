#include <iostream>
#include <string>

using namespace std;
int num[41];
int dynamic[41];

int main(){
	string number;
	int size = 0;
	getline(cin, number);
	size = number.size();


	for (int i = 0; i < size; i++){
		num[i] = number[i] - 48;
	}
	dynamic[0] = 1;
	for (int i = 1; i < size; i++){
		if (num[i] != 0){
			dynamic[i] += dynamic[i - 1];
		}
		int temp = num[i - 1] * 10 + num[i];
		if (num[i-1] != 0 && temp >0 && temp < 35){
			if (i == 1){
				dynamic[i] += 1;
			}
			dynamic[i] += dynamic[i - 2];
		}
	}

	cout << dynamic[size-1] <<endl;

	return 0;
	
}