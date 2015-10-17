#include <iostream>

using namespace std;

int arr[301][21];
int d[301][21];
int p[301][21];
int M, N;
void bt(int m, int n) {
	if (n == 0) { return; }
	bt(m - p[m][n], n - 1);
	cout << p[m][n] << " ";
}

int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		int temp;
		cin >> temp;
		for (int j = 1; j <= N; j++) {
			cin >> arr[temp][j];
			d[temp][j] = arr[temp][j];
			p[temp][j] = temp;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k <= j; k++) {
				if (d[j][i] < d[k][i - 1] + arr[j - k][i]) {
					d[j][i] = d[k][i - 1] + arr[j - k][i];
					p[j][i] = j-k;
				}
			}
		}
	}
	cout << d[M][N] << endl;
	bt(M, N);
	  
	return 0;
}

//#include<iostream>
//using namespace std;
//
//#define Nmax 310
//
//int N, M;
//int A[Nmax][Nmax], D[Nmax][Nmax], P[Nmax][Nmax];
//
//void input()
//{
//	int a;
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		cin >> a;
//		for (int j = 0; j<M; j++) {
//			cin >> A[a][j];
//			D[a][j] = A[a][j];
//			P[a][j] = a;
//		}
//	}
//}
//
//void dfs(int y, int x)
//{
//	if (x == -1) return;
//	dfs(y - P[y][x], x - 1);
//	cout << P[y][x] << " ";
//}
//
//void process()
//{
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j<M; j++) {
//			for (int k = 1; k <= i; k++) {
//				if (D[i][j] < D[k][j - 1] + A[i - k][j]) {
//					D[i][j] = D[k][j - 1] + A[i - k][j];
//					P[i][j] = i - k;
//				}
//			}
//		}
//	}
//}
//
//void output()
//{
//	cout << D[N][M - 1] << endl;
//	dfs(N, M - 1);
//}
//
//int main()
//{
//	input();
//	process();
//	output();
//	return 0;
//}