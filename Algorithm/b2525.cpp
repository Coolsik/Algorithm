#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int hour, min, time, tmp_hour, tmp_min;

	cin >> hour >> min >> time;

	tmp_hour = time / 60;
	tmp_min = time % 60;

	hour += tmp_hour;

	min += tmp_min;
	
	if (min >= 60){
		min = min - 60;
		hour++;
	}

	if (hour > 23){
		hour = hour - 24;
	}

	cout << hour << " " << min << endl;

	return 0;
}