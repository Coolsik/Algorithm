#include <iostream>

using namespace std;

int main(){
	int w, h, p, q, t, x_dir = 1, y_dir=1;

	cin >> w >> h >> p >> q >> t;

	for (int i = 0; i < t%(w*2); i++){
		if (p == w || p == 0){ x_dir = x_dir * -1; }
		p = p + x_dir;
		
		
	}
	for (int i = 0; i < t%(h*2); i++){
		if (q == h || q == 0){ y_dir = y_dir * -1; }
		q = q + y_dir;
	}

	cout << p <<" "<< q << endl;

	return 0;
}