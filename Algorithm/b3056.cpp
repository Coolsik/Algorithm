/*
D[i][j] = i요원까지 왔을 때 j일들을 끝냈을 경우의 최대확률

j 일들 --> 1번일만 했을 때 001 => 1
		 1,3 번 일 했을 때 101 => 5
		 2번 일만 했을 때  010 => 2

d[i][j] = d[i-1][k] + A[i][x] ;; k+2^x = j 가 된다

*/

#include <iostream>
#include <cstdio>
using namespace std;
int N;
double max_per = 0;
int arr[21][21];
int check[21];
int cnt = 0;
void process(int index, int c[], double per) {
	if (per <= max_per) return;
	if (index == N) {
		if (max_per < per) {
			max_per = per;
		}
	}
	for (int i = 0; i < N; i++) {
		if (c[i] == 0) {
			c[i] = 1;
			process(index + 1, c, per * arr[i][index] / (double)100);
			c[i] = 0;
		}
	}
}
int main() {
	
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	process(0, check, 100);
	printf("%lf\n", max_per);
}


//#include <iostream>
//#include <cstdio>
//using namespace std;
//int arr[21][21];
//double value[21];
//int main() {
//	int N;
//	int max = 0;
//	int max_i, max_j;
//	cin >> N;
//	int index = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j] > max) {
//				max = arr[i][j];
//				max_i = i;
//				max_j = j;
//			}
//		}
//	}
//	
//	int test = N;
//	while (test--> 0) {
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (arr[i][j] >= max) {
//					max_i = i;
//					max_j = j;
//					max = arr[i][j];
//				}
//			}
//		}
//		value[max_j] = max / (double)100;
//		for (int i = 0; i < N; i++) {
//			arr[i][max_j] = 0;
//			arr[max_i][i] = 0;
//		}
//		max = 0;
//	}
//	double result = 1;
//	for (int i = 0; i < N; i++) {
//		result *= value[i];
//	}
//	result *= 100;
//	printf("%lf", result);
//	return 0;
//}



//#include <iostream>
//#include <cstdio>
//#include <list>
//#include <algorithm>
//using namespace std;
//
//typedef struct b{
//	int val;
//	int x;
//	int y;
//}bond;
//
//bond arr[401];
//double value[21];
//struct cmp{
//	bool operator()(const bond& a, const bond& b) {
//		return a.val > b.val;
//	}
//};
//
//int main() {
//	int N;
//	cin >> N;
//	//vector<int> v;
//	list<int> l;
//	int index = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			int temp;
//			cin >> temp;
//			bond t{ temp, i, j };
//			arr[index++] = t;
//		}
//	}
//	
//	sort(arr, arr + index, cmp());
//
//	int itr = N;
//	while (itr-- > 0) {
//		value[arr[0].y] = (double)arr[0].val / (double)100;
//		int t_x=arr[0].x, t_y=arr[0].y;
//		int target = N*N;
//		for (int i = 0; i < target; i++) {
//			if (arr[i].x == t_x || arr[i].y == t_y) {
//				arr[i].val = -1;
//			}
//		}
//		sort(arr, arr + index, cmp());
//	}
//	double sum=1;
//	for (int i = 0; i < N; i++) {
//		sum *= value[i];
//	}
//	printf("%.5lf", sum * 100);
//	//cout << sum*100 << endl;
//	return 0;
//}