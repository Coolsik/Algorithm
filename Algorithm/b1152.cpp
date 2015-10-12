#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char str[1000002];
int main(){
	/*
	int sum = 0;
	cin.getline(str, sizeof(str));
	int len = strlen(str);
	for (int i = 0; i < len; i++){
		if (str[i] == ' ' && len-1 != i && i!=0){
			sum++;
		}
	}

	cout << sum+1;*/

	string A;
	int cnt=0;
	while (1){
		cin >> A;
		if (cin.eof()){
			break;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}