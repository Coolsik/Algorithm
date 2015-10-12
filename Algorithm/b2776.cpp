#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int book1[1000001];
int book2[1000001];
int main(){
	int N, M, testcase;
	scanf("%d", &testcase);
	while (testcase-- > 0){
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			scanf("%d", &book1[i]);
		}
		sort(book1, book1 + N);
		scanf("%d", &M);
		for (int i = 0; i < M; i++){
			int temp;
			scanf("%d", &temp);
			if (binary_search(book1, book1 + N, temp)){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}

	}


	return 0;
}