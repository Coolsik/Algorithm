#include <stdio.h>

#define INF 987654321

int A[702][702][11];
int M[702][702], X, Y, Limit, Ans, Xmin, Ymin, Xmax, Ymax;

void Input() {
	int i, j;
	scanf("%d %d %d", &X, &Y, &Limit);
	for (i = 0; i<Y; i++) {
		for (j = 0; j<X; j++) scanf("%d", &M[i][j]);
	}
	for (i = 0; i<Y; i++) M[i][X] = INF;
	for (i = 0; i<X; i++) M[Y][i] = INF;
}

void Check() {
	int x, y, l, i, j, low, high;
	for (y = 0; y<Y; y++) {
		for (x = 0; x<X; x++) {
			for (l = 0; l <= Limit; l++) {
				low = M[y][x] + l - Limit;
				high = M[y][x] + l;
				for (i = 0; i <= 100; i++) {
					if (M[y][x + i] < low || M[y][x + i] > high) {
						A[y][x][l] = i;
						break;
					}
				}
				if (i > 100) {
					A[y][x][l] = 100;
				}
			}
		}
	}
}

void Find_Ans() {
	int x, y, i, j, next, l, y_span, min, temp;
	for (y = 0; y<Y; y++) {
		for (x = 0; x<X; x++) {
			for (l = Limit; l >= 0; l--) {
				min = A[y][x][l];
				i = 0;
				while (1) {
					next = l + M[y][x] - M[y + i][x];
					if (next>Limit || next<0) break;
					else {
						if (min > A[y + i][x][next]) min = A[y + i][x][next];
						if (min == 0) {
							x = x;
						}
						temp = (i + 1) * (min);
						if (temp > Ans) {
							Ans = temp;
							Xmin = x;
							Ymin = y;
							Xmax = x + min - 1;
							Ymax = y + i;
						}
					}
					i++;
				}
			}
		}
	}
}

int main() {
	Input();
	Check();
	Find_Ans();
	printf("%d %d %d %d", Xmin + 1, Y - Ymax, Xmax + 1, Y - Ymin);
	return 0;
}