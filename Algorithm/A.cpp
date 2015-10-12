#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){

	int arr[3] = { 0, 1, 2 };
	int a,b,N, index = 0;
	scanf("%d", &N);
	cout << arr[index++] << endl;
	while (N-->0){
		scanf("%d %d", &a, &b);
		cout << arr[index++] << endl;
		if (index == 3){
			index = 0;
		}
	}

	return 0;
}