#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int coin[101];
// int d[100][10000];
map<pair<int, int>, int> d;
map<pair<int, int>, int>::iterator it;
int func(int c, int k) {
	if (k == 0) { return 1; }
	if (c<0 || k<0) return 0;

	//int &ret = d[c][k];
	//if (ret == -1) {
	//
	pair<int, int> temp(c, k);
	it = d.find(temp);
	int ret = 0;
	if(it==d.end())
	{
		ret = func(c, k - coin[c]) + func(c - 1, k);
		d[temp] = ret;
	}
	else {
		ret = it->second;
	}
	return ret;

}

int main() {
	int n, k;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	//memset(d, -1, sizeof(d));
	
	cout << func(n-1, k);

	return 0;
}