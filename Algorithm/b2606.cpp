#include <iostream>

using namespace std;

bool virus[101];
bool computer[101][101];
void process(int num, int max){
	for (int i = 0; i < max; i++){
		computer[i][num] = false;
	}
	for (int i = 1; i < max; i++){
		if (computer[num][i]){
			virus[i] = true;
			process(i, max);
		}
	}
}

int main(){

	int max_computer, testcase, count =0;
	cin >> max_computer >> testcase;

	while (testcase-->0){
		int i, j;
		cin >> i >> j;
		computer[i][j] = true;
		computer[j][i] = true;
	}

	process(1, max_computer+1);

	for (int i = 0; i < 101; i++){
		if (virus[i]){
			count++;
		}
	}
	cout << count << endl;

	return 0;
}