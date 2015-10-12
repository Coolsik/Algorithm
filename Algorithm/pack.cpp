#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int d[1002][101];
int N, W;
struct thing {
	int w;
	int z;
	string name;
};

struct thing arr[101];

int max(int a, int b) {
	return a > b ? a : b;
}

bool cmp(thing a, thing b) {
	return a.w < b.w;
}

int func(int w, int i) {
	int &ret = d[w][i];
	if (w < 0) return -999999999;
	if (i == N) return 0;


	if (ret == -1) {
		/*ret = func(w, i + 1);
		if (w >= arr[i].w) {
			ret = max(func(w - arr[i].w, i + 1) + arr[i].z, ret);
		}*/
		ret = max(func(w - arr[i].w, i + 1) + arr[i].z, func(w,i+1));
	}
	return ret;

}

void bt(int w, int i, vector<string> &item) {
	if (i == N) return;
	if (func(w, i) == func(w, i + 1)) {
		bt(w, i + 1, item);
	}
	else {
		item.push_back(arr[i].name);
		bt(w - arr[i].w, i + 1, item);
	}
}
int main() {
	int testcase;
	cin >> testcase;

	while (testcase-- > 0) {
		

		cin >> N >> W;
		
		for (int i = 0; i < N; i++) {
			cin >> arr[i].name >> arr[i].w >> arr[i].z;
		}
		memset(d, -1, sizeof(d));
		cout << func(W, 0) << " ";
		vector<string> item;
		bt(W, 0, item);
		cout << item.size() << endl;
		for (string s : item) {
			cout << s << endl;
		}

	}


	return 0;
}