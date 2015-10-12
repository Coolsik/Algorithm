#include <iostream>

using namespace std;

int gcd(int a, int b){
	if (a%b == 0){
		return b;
	}
	gcd(b, a%b);
}

int main(){
	int a, b, testcase;

	cin >> testcase;

	while (testcase-- > 0){
		cin >> a >> b;
		cout << a*b/gcd(a, b) << endl;
	}

	
}