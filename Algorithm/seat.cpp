#include <iostream>
using namespace std;
int d[41] = { 1,1, };

int fibo(int n) {
	if (d[n] != 0) { return d[n]; }
	return d[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
	fibo(41);
	int N, M;
	cin >> N >> M;
	int prev = 0;
	int sum = 0;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		if (sum == 0) {
			sum += d[temp - prev - 1];
		}
		else {
			sum*= d[temp - prev - 1];
		}
		prev = temp;
	}
	
	if (sum == 0) {
		sum += d[N - prev];
	}
	else {
		sum *= d[N - prev];
	}
	cout << sum;
	
	

	return 0;
}