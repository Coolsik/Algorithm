#include <iostream>

using namespace std;

int main(){
	int paper[7];
	int result = 0;
	for (int i = 1; i <= 6; i++){
		cin >> paper[i];
	}

	result += paper[6];

	if (paper[5]){
		if (paper[1] = paper[1] - (paper[5] * 11) < 0) paper[1] = 0;
		result += paper[5];
	}
	if (paper[4]){
		paper[2] = paper[2] - paper[4] * 5;
		if (paper[2] < 0){
			paper[1] += paper[2] * 4;
			if (paper[1] < 0) paper[1] = 0;
			if (paper[2] < 0) paper[2] = 0;
		}
		result += paper[4];
	}

	if (paper[3]){
		result += paper[3] / 4;
		if (paper[3] % 4){
			if (paper[2] > 0){
				paper[2] += (paper[3]%4 - 4) * 9;
				if (paper[2] < 0){
					paper[1] += paper[2] * 4;
					if (paper[1] < 0){ paper[1] = 0; }
					paper[2] = 0;
				}
			}
			result++;
		}

	}
	if (paper[2]){
		result += paper[2] / 9;
		if (paper[2] % 9){
			paper[1] += (paper[2] % 9 - 9) * 4;
			if (paper[1] < 0) paper[1] = 0;
			result++;
		}
	}
	if (paper[1]){
		result += paper[1] / 36;
		if (paper[1] % 36){ result++; }
	}

	cout << result << endl;

	return 0;
}