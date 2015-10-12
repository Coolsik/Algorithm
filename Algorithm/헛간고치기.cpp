// Greedy로 풀기
#include <iostream>
#include <algorithm>
using namespace std;
int M, S, C;
int barn[201], diff[201];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> M >> S >> C;
	for (int i = 0; i < C; i++) {
		cin >> barn[i];
	}
	sort(barn, barn + C);

	for (int i = 1; i < C; i++) {
		diff[i] = barn[i] - barn[i - 1];
	}

	if (M >= C) {
		cout << C;
	}
	else {
		sort(diff, diff + C, cmp);

		int result = barn[C - 1] - barn[0] + 1;
		for (int i = 0; i < M - 1; i++) {
			result -= diff[i] - 1;
		}
		cout << result;
	}
	return 0;
}


/*
#include <iostream>
using namespace std;
#define FAIL 999999999

int min(int a, int b) { return a > b?b:a; }

int M, S, C;
int barn[201];
int d[51][201];
int func(int i, int j) {
	int& ret = d[i][j];
	if (i > M) { return FAIL; }	// 판자 너무 많음..
	if (j == C - 1) { 
		return 1; 
	}

	if (ret == 0) {
		ret = min(func(i, j + 1) + d[i][j], func(i+1, j+1)+1);
	}
	else {
		ret = d[i][j];
	}
	return ret;
}


int main() {
	//f(i, j) = (새로 덮는경우, 연장하는경우) 판자의 갯수 i, j번째까지
	//memset(d, -1, sizeof(d));
	cin >> M >> S >> C;
	for (int i = 0; i < C; i++) {
		cin >> barn[i];
	}
	cout << func(0, 0);

	return 0;
}

*/