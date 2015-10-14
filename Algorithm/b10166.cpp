#include <iostream>
using namespace std;
int seat[2001][2001];
int gcd(int a, int b) {
	if (a%b == 0) {
		return b; 
	}
	else { 
		int temp = b;
		b = a%b;
		a = temp; 
	}
	gcd(a, b);
}

int main() {
	int d1, d2;

	cin >> d1 >> d2;

	int cnt = 0;
	int temp_i=0, temp_j=0;
	for (int i = d1; i <= d2; i++) {
		for (int j = 1; j <= i; j++){
			int temp = gcd(i, j);
			temp_i = i / temp;
			temp_j = j / temp;
			if (seat[temp_i][temp_j] == 0) {
				cnt++;
				seat[temp_i][temp_j] = 1;
			}
		}
	}
	
	cout << cnt;
	return 0;
}