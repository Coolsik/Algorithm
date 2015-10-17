#include <iostream>
#include <string.h>
using namespace std;
long long d[201][201][201];
long long func(int n, int k, int prev) {
	long long &ret = d[n][k][prev];
	if (k == 0 && n == 0) return 1;
	if (prev > n) return 0;
	if (k <= 0) return 0;
	if (n <= 0) return 0;
	if (n < k) return 0;
	
	

	long long sum = 0;
	if (ret == -1) {
		for (int i = prev; i <= n/k; i++) {
			sum += func(n - i, k - 1, i);
		}
		ret = sum;
	}
	
	return ret;
}

int main() {
	int N, K;
	cin >> N >> K;
	memset(d, -1, sizeof(d));
	cout << func(N, K, 1);

	return 0;
}