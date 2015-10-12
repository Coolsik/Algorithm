#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
string btoo[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
int main(){
	char a;
	int cnt = 0;
	string num;
	cin >> num;
	for (int i = 0; i < num.length(); i++){
		if (cnt == 0 && num[i] <= '3'){
			if (num[i] == '1') cout << "1";
			else if (num[i] == '2') cout << "10";
			else if (num[i] == '3') cout << "11";
		}
		else{
			cout << btoo[num[i] - 48];
		}
		cnt++;
	}
	

	return 0;
}