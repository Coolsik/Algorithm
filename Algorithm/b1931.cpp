#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int, int> > r;
int nmax = 0;
struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
};

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		//scanf("%d %d", &room[i].first, &room[i].second);
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		pair<int, int> temp(t1, t2);
		r.push_back(temp);
	}

	sort(r.begin(), r.end(), cmp());
	
	int value = -9999999;

	for (int i = 0; i < N; i++) {
		if (r[i].first >= value) {
			nmax++;
			value = r[i].second;
		}
	}
	
	cout << nmax;

	return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int N;
////int room[2][100001];
//
////pair<int, int> room[100001];
//
//vector<pair<int, int> > r;
//
//int d[25];
//int cnt = 0;
//int nmax = 0;
//int max(int a, int b) {
//	return a > b ? a : b;
//}
//
//void func(int t) {
//	d[t] = d[t - 1];
//	while(r.size() > cnt && r[cnt].second == t) {
//		if (r[cnt].second == r[cnt].first) {
//			if (t != 0) {
//				d[t] = d[t - 1] + 1;
//			}
//			else {
//				d[t]++;
//			}
//		}
//		else {
//			d[t] = max(max(d[r[cnt].first] + 1, d[t - 1]), d[t]);
//		}
//		cnt++;
//	}
//	nmax = max(d[t], nmax);
//}
//
//struct cmp {
//	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
//		return a.second < b.second;
//	}
//};
//
//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		//scanf("%d %d", &room[i].first, &room[i].second);
//		int t1, t2;
//		scanf("%d %d", &t1, &t2);
//		pair<int, int> temp(t1, t2);
//		r.push_back(temp);
//	}
//
//	sort(r.begin(), r.end(), cmp());
//	
//	for (int i = 0; i < 25; i++) {
//		func(i);
//	}
//	
//	cout << nmax;
//
//	return 0;
//}