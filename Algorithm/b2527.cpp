#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int x1, y1, p1, q1, x2, y2, p2, q2;
	int testcase = 4;
	int x[4], y[4];

	min(p2, p1);

	while (testcase-- > 0){
		int x_count = 0, y_count = 0;
		int *result = NULL;
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
		x[0] = x1;
		x[1] = p1;
		x[2] = x2;
		x[3] = p2;
		y[0] = y1;
		y[1] = q1;
		y[2] = y2;
		y[3] = q2;

		for (int i = 0; i < 3; i++){
			for (int j = i + 1; j < 4; j++){
				if (x[i] == x[j]){
					x_count++;
				}
			}
			for (int j = i + 1; j < 4; j++){
				if (y[i] == y[j]){
					y_count++;
				}
			}
		}

		if (x_count && y_count){
			if (x1 == x2 && y1 == q2 || x2==p1 && q1==q2){
				cout << "b" << endl;
				continue;
			}
			
			if (x_count == 2 || y_count == 2){
				cout << "a" << endl;
				continue;
			}
			
			if (x1 == x2 || y1 == y2 || p1==p2 || q1==q2){
				cout << "a" << endl;
				continue;
			}

			cout << "c" << endl;
			continue;
		}

		if (x1>p2 || y1 > q2 || p1 < x2 || q1 < y2){
			cout << "d" << endl;
			continue;
		}
		if (x_count || y_count){
			if (x1 == x2 || y1 == y2){
				cout << "a" << endl;
				continue;
			}
			cout << "b" << endl;
			continue;
		}
		


		cout << "a" << endl;

	}

	return 0;
}