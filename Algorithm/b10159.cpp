#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

bool check[101][101];
int main(){
	int N,M,x,y; scanf("%d%d",&N,&M);
	for(int i=0; i<M; i++){
		scanf("%d%d",&x,&y);
		check[x][y] = true;
	}
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			if(check[i][k]){
				for(int j=1; j<=N; j++){
					if(check[k][j]) check[i][j] = true;
				}
			}
		}
	}
	for(int i=1; i<=N; i++){
		int cnt = 0;
		for(int j=1; j<=N; j++){
			if(i==j) continue;
			if(!check[i][j] && !check[j][i]) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}


#if 0

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int arr[2001][2];
int check[101] = { 0, };
queue<int> que;
int main(){
	

	int N, M;
	int A, B;
	int count;
	int check_num;
	cin >> N >> M;

	for (int i = 0; i < M; i++){
		cin >> A >> B;
		arr[i][0] = A;
		arr[i][1] = B;
	}

	for (int i = 1; i <= N; i++){
		int count = 0;
		check[i] = 1;
		for (int j = 0; j < M; j++){
			if (arr[j][0] == i) que.push(arr[j][1]);
		}
		while (que.size()){
			check_num = que.front();
			check[check_num] = 1;
			que.pop();

			for (int j = 0; j < M; j++){
				if (arr[j][0] == check_num && check[arr[j][1]] == 0) que.push(arr[j][1]);
			}
		}

		for (int j = 0; j < M; j++){
			if (arr[j][1] == i) que.push(arr[j][0]);
		}
		while (que.size()){
			check_num = que.front();
			check[check_num] = 1;
			que.pop();

			for (int j = 0; j < M; j++){
				if (arr[j][1] == check_num && check[arr[j][0]]==0) que.push(arr[j][0]);
			}
		}

		for (int j = 1; j <= N; j++){
			if (check[j] == 0) count++;
		}
		cout << count << endl;
		for (int j = 0; j < 101; j++){
			check[j] = 0;
		}
	}


	return 0;
}
#endif


#if 0

#include <iostream>

using namespace std;

int arr[101][101];
int check[101] = { 0, };
bool process(int u, int v, int N){
	if (arr[u][v] == 1){
		return true;
	}
	for (int i = 1; i <= N; i++){
		if (arr[u][i] == 1){
			if (process(i, v, N) == true) return true;
		}
	}
	return false;
}

int main(){
	int N, M;
	int A, B;
	int count;
	cin >> N >> M;

	for (int i = 0; i < M; i++){
		cin >> A >> B;
		arr[A][B] = 1;
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i == j) continue;
			if (process(i, j, N) == false && process(j,i,N)==false) check[i]++;
		}
		cout << check[i] << endl;
	}

	return 0;

}

#endif


#if 0

#include <iostream>

using namespace std;

int arr[101][101] = { 0, };

void process(int i, int now, int N){
	for (int j = 0; j < N; j++){
		if (arr[i][j] == 1){
			arr[now][j] = 1;
			process(j, now, N);
		}
	}
}

int main(){
	int N, M;
	int A, B;
	int count;
	cin >> N >> M;

	for (int i = 0; i < M; i++){
		cin >> A >> B;
		arr[A][B] = 1;
		arr[B][A] = -1;
	}
	for (int now = 1; now <= N; now++){
		for (int i = 1; i <= N; i++){
			if (arr[now][i] == 1){
				process(i, now, N);
			}
		}
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (arr[i][j] == 1){
				arr[j][i] = -1;
			}
		}
	}

	for (int i = 1; i <= N; i++){
		count = 0;
		for (int j = 1; j <= N; j++){
			if (arr[j][i] == 0){ count++; }
		}
		cout << count - 1 << endl;
	}


	return 0;
}

#endif