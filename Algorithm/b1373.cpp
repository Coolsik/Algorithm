#include <iostream>
#include <string>
#include <cstdio>
#include <math.h>
using namespace std;
char *arr[1000000];
int main(){
	string num;
	cin >> num;
	int len = num.length();
	int start=0;
	if (len % 3 == 1){
		printf("%c", num[0]);
		start = 1;
	}
	else if (len % 3 == 2){
		int temp = (num[0] - 48) * 2 + num[1] - 48;
		printf("%d", temp);
		start = 2;
	}

	for (int i = start; i < len; i=i+3){
		int temp =(num[i] - 48) * 4 + (num[i + 1] - 48) * 2 + (num[i + 2] - 48);
		printf("%d", temp);
	}
}