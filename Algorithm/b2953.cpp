#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int a, b, c, d;
	int num = 0, max = 0;
	for (int i = 1; i < 6; i++){
		cin >> a >> b >> c >> d;
		int sum = a + b + c + d;
		if (sum > max){
			max = sum;
			num = i;
		}
	}
	printf("%d %d", num, max);
	return 0;
}