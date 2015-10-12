#include <iostream>
using namespace std;
#define init_MAX 999999999
int N, K;
int coin[101];
int d[101][10001];

int min(int a, int b) {
	return a < b ? a : b;
}

void func(int n, int k) {
	if (k - coin[n-1] >= 0) {
		d[n][k] = min(d[n - 1][k], d[n][k - coin[n-1]]+1);
	}
	else {
		d[n][k] = d[n - 1][k];
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	for (int i = 0; i <= K; i++) {
		d[0][i] = init_MAX;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			func(i, j);
		}
	}

	cout << d[N][K];

	return 0;
}



//#include <iostream>
//#include <cstring>
//#include <map>
//using namespace std;
//#define init_MAX 999999999
//int coin[101];
//int d[101][10001];
//int noc = init_MAX;
//int func(int c, int k, int n) {
//	if (k == 0) { 
//		if (n < noc) {
//			noc = n;
//		}
//		return 1; 
//	}
//	if (c<0 || k<0) return 0;
//
//	int &ret = d[c][k];
//	if (ret == -1) {
//		ret = func(c, k - coin[c], n +1) + func(c - 1, k, n);
//	}
//	return ret;
//
//}
//
//int main() {
//	int n, k;
//
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) {
//		cin >> coin[i];
//	}
//	memset(d, -1, sizeof(d));
//	func(n - 1, k, 0);
//	if (noc == init_MAX) {
//		cout << "-1";
//	}
//	else {
//		cout << noc;
//	}
//	return 0;
//}