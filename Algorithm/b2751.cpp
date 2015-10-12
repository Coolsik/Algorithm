#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
bool arr[2000001] = { false, };
int main(){
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		int temp;
		scanf("%d", &temp);
		arr[temp+1000000] = true;
	}

	for (int i = 0; i < 2000001; i++){
		if (arr[i]){ printf("%d\n", i - 1000000); }
	}
	return 0;
}