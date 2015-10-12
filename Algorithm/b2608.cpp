#include <iostream>

using namespace std;

char result[100];

int rome2int(char *arr, int max){
	int int_result = 0;
	for (int i = 0; i < max; i++){
		if (i < max - 1){
			if (arr[i] == 'I'&&arr[i + 1] == 'V'){
				int_result += 4;
				i++;
				continue;
			}
			if (arr[i] == 'I'&&arr[i + 1] == 'X'){
				int_result += 9;
				i++;
				continue;
			}
			if (arr[i] == 'X'&&arr[i + 1] == 'L'){
				int_result += 40;
				i++;
				continue;
			}
			if (arr[i] == 'X'&&arr[i + 1] == 'C'){
				int_result += 90;
				i++;
				continue;
			}
			if (arr[i] == 'C'&&arr[i + 1] == 'D'){
				int_result += 400;
				i++;
				continue;
			}
			if (arr[i] == 'C'&&arr[i + 1] == 'M'){
				int_result += 900;
				i++;
				continue;
			}
		}

		if (arr[i] == 'I'){
			int_result += 1;
			continue;
		}
		if (arr[i] == 'V'){
			int_result += 5;
			continue;
		}
		if (arr[i] == 'X'){
			int_result += 10;
			continue;
		}
		if (arr[i] == 'L'){
			int_result += 50;
			continue;
		}
		if (arr[i] == 'C'){
			int_result += 100;
			continue;
		}
		if (arr[i] == 'D'){
			int_result += 500;
			continue;
		}
		if (arr[i] == 'M'){
			int_result += 1000;
			continue;
		}
	}
	//cout << int_result<<endl;
	return int_result;
}

void int2rome(int x){
	int thou, hund, ten, one;

	int i = 0;
	thou = x / 1000;
	hund = (x % 1000) / 100;
	ten = (x % 100) / 10;
	one = x % 10;

	while (thou-- > 0){
		result[i++] = 'M';
	}

	for (; hund>0; hund--){
		if (hund == 9){
			result[i++] = 'C';
			result[i++] = 'M';
			break;
		}
		else if (hund >= 5){
			result[i++] = 'D';
			hund = hund - 4;
		}
		else if (hund == 4){
			result[i++] = 'C';
			result[i++] = 'D';
			break;
		}
		else{
			result[i++] = 'C';
		}
	}

	for (; ten>0; ten--){
		if (ten == 9){
			result[i++] = 'X';
			result[i++] = 'C';
			break;
		}
		else if (ten >= 5){
			result[i++] = 'L';
			ten = ten - 4;
		}
		else if (ten == 4){
			result[i++] = 'X';
			result[i++] = 'L';
			break;
		}
		else{
			result[i++] = 'X';
		}
	}

	for (; one>0; one--){
		if (one == 9){
			result[i++] = 'I';
			result[i++] = 'X';
			break;
		}
		else if (one >= 5){
			result[i++] = 'V';
			one = one - 4;
		}
		else if (one == 4){
			result[i++] = 'I';
			result[i++] = 'V';
			break;
		}
		else{
			result[i++] = 'I';
		}
	}
}

int main(){
	char num1[100];
	char num2[100];
	int intresult = 0;
	char char_result[100];
	int num1_max = 0, num2_max = 0;
	cin >> num1 >> num2;

	for (int i = 0; i < 100; i++){
		if (num1[i] != '\0'){
			num1_max++;
			continue;
		}
		break;
	}

	for (int i = 0; i<100; i++){
		if (num2[i] != '\0'){
			num2_max++;
			continue;
		}
		break;
	}

	intresult += rome2int(num1, num1_max);
	intresult += rome2int(num2, num2_max);

	cout << intresult << endl;

	int2rome(intresult);

	cout << result << endl;

	return 0;
}