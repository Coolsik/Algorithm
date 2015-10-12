#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <algorithm>

int check[26];
void process(char *s){




}

int main(){
	char str[21];
	int i,j, k;

	scanf("%s", str);

	for (i = 0; i<21; i++){
		if (str[i] == '\0') break;
		check[str[i] - '0']++;
	}
	k = 0;
	for (i = 0; i < 26; i++){
		for (j = 0; j < check[i]; j++){
			str[k++] = '0' + i;
		}
	}

	process(str);



	return 0;
}
