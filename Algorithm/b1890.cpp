#include <iostream>

using namespace std;

int arr[101][101];
long long d[101][101] = { 0, };
bool check[101][101];
int N;
long long func(int y, int x) {
	if (y == N - 1 && x == N - 1) {
		return 1;
	}
	if (y >= N || x >= N) {
		return 0;
	}
	int jmp = arr[y][x];
	if (jmp == 0) {
		return 0;
	}
	long long &ret = d[y][x];
	if (check[y][x] == true) {
		return d[y][x];
	}
	else {
		ret = func(y + jmp, x) + func(y, x + jmp);
		check[y][x] = true;
	}
	return ret;
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> arr[i][j];
		}
	}
	
	cout << func(0, 0) << endl;

	return 0;
}

