#include <iostream>

using namespace std;

int main(){
	int n, sum = 0;
	cin >> n;
	sum += n;
	for (int i = 2; i < 10000; i++){
		for (int j = i; j < 10000; j++){
			if (i*j <= n){
				sum++;
			}
			else{
				break;
			}
		}
	}
	cout << sum;
	return 0;
}