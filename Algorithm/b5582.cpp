#include <iostream>
#include <string.h>
using namespace std;

int map[4002][4002];

int main() {
	char s1[4001], s2[4001];
	int N, M;
	scanf("%s", s1);
	scanf("%s", s2);

	N = strlen(s1);
	M = strlen(s2);
	int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				map[i][j] = map[i - 1][j - 1] + 1;
				if (map[i][j] > max) {
					max = map[i][j];
				}
			}
		}
	}

	cout << max << endl;

	return 0;
}