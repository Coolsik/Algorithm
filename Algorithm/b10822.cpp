#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	char temp[100];
	int sum = 0;
	int index = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++){
		if (str[i] != ','){
			temp[index++] = str[i];
		}
		if (str[i] == ',' || str.length() -1 == i){
			temp[index] = '\0';
			index = 0;
			sum += atoi(temp);
		}
	}

	cout << sum;
	return 0;
}