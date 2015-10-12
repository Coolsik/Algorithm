#include <iostream>

using namespace std;

int main() {
	int h, m, s, time;
	cin >> h >> m >> s >> time;

	time += h * 3600;
	time += m * 60;
	time += s;

	if (time >= 86400) {
		time %= 86400;
	}

	h = time / 3600;
	time -= h * 3600;
	m = time / 60;
	time -= m * 60;
	s = time;

	cout << h << " " << m << " " << s;
	
	return 0;
}