#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int cnt=0;
	int max = 0, temp, x, y;
	for (int i = 1; i < 10; i++){
		for (int j = 1; j < 10; j++){
			cin >> temp;
			if (temp > max){
				max = temp;
				x = i;
				y = j;
			}
		}
	}

	cout << max << endl;
	cout << x << " " << y << endl;

	return 0;
}