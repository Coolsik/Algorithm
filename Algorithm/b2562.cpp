#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<pair<int, int> > vec;
	

	for (int i = 1; i <= 9; i++){
		pair<int, int> temp;
		cin >> temp.first;
		temp.second = i;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	cout << vec.back().first << endl;
	cout << vec.back().second << endl;
	

	return 0;
}