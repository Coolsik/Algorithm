#include <iostream>
#include <cstring>
using namespace std;

int MAX(int a, int b) {
	return a > b ? a : b;
}

int drink[10001];
int d[10001][2];
int N;
int func(int n, int k) {
	int &ret = d[n][k];
	if (n > N-1) { return 0; }	// 포도주 잔의 개수를 넘을경우
	if (k == 2) { return 0; }		// 3번연속 마실경우

	if (ret == -1) {
		ret = MAX(MAX(func(n + 1, k + 1), func(n+2, 0))+drink[n], func(n+1, 0));
	}

	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &drink[i]);
	}
	memset(d, -1, sizeof(d));
	
	cout << func(0, 0);
	
	return 0;
}