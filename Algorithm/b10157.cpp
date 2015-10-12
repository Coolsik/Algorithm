#include <iostream>

using namespace std;

int arr[1002][1002];
int main(){
	int C, R, K;
	int x_dir = 1, y_dir = 0, x=1, y=1;
	cin >> C >> R >> K;
	
	if (C*R >= K){
		for (int i = 1; i <= C*R; i++){

			arr[y][x] = i;
			if (i == K){ cout << y << " " << x << endl; break; }

			if (x + x_dir > 0 && x + x_dir <= R && y + y_dir > 0 && y + y_dir <= C && arr[y + y_dir][x + x_dir] == 0){
				x = x + x_dir;
				y = y + y_dir;
			}
			else{
				if (x_dir == 1 && y_dir == 0){
					x_dir = 0; y_dir = 1;
				}
				else if (x_dir == 0 && y_dir == 1){
					x_dir = -1; y_dir = 0;
				}
				else if (x_dir == -1 && y_dir == 0){
					x_dir = 0; y_dir = -1;
				}
				else if (x_dir == 0 && y_dir == -1){
					x_dir = 1; y_dir = 0;
				}

				i--;
			}
		}
	}
	else{
		cout << "0" << endl;
	}
	

	return 0;

}