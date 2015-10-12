#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

#define N 51
char map[N][N];
int w,h;

int max(int a,int b) {
	return a>b ? a:b;
}

int bfs(int y,int x) {
	bool chk[N][N] = {0,};
	int dist[N][N];

	queue< pair < int, int > > que;

	dist[y][x] = 0;
	chk[y][x] = 1;
	que.push( make_pair(x,y) );

	int ans = 0;

	while(!que.empty()) {
		int tx = que.front().first;
		int ty = que.front().second;
		ans = max(ans,dist[ty][tx]);
		que.pop();

		for(int i=0;i<4;i++) {
			int px[] = {1,0,-1,0};
			int py[] = {0,1,0,-1};

			int nx = tx+px[i];
			int ny = ty+py[i];

			if( (nx < 0) || (nx >= w) || (ny < 0) || (ny >= h) )
				continue;
			if( map[ny][nx]=='W' )
				continue;
			if( chk[ny][nx]==1 )
				continue;

			dist[ny][nx] = dist[ty][tx] + 1;
			if (dist[ny][nx] == 91){
				puts("coolsik");
			}
			chk[ny][nx] = 1;
			que.push( make_pair(nx,ny) );
		}
	}
	return ans;
}

int main() {

	scanf("%d %d\n",&h,&w);
	for(int i=0;i<h;i++)
		gets(map[i]);

	int ans = 0;

	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if( map[i][j]=='L' )
				ans = max(ans,bfs(i,j));

	printf("%d",ans);
}

#endif


#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

typedef struct Info{
	int x;
	int y;
	int cnt;
}Info;
int check_cnt;
int map[51][51];
queue<Info> my_queue;
int H, W;

void bfs(int _x, int _y){
	Info temp;
	int temp_map[51][51];
	int visit[51][51];
	for(int i = 0; i < W; i++){
		for (int j = 0; j < H; j++){
			temp_map[j][i] = 0;
			visit[j][i] = map[j][i];
		}
	}
	temp.x = _x; temp.y = _y; temp.cnt = 0;
	my_queue.push(temp);
	int cnt;
	while (my_queue.size() != 0){
		int x = my_queue.front().x;
		int y = my_queue.front().y;
		cnt = my_queue.front().cnt;
		my_queue.pop();

		if (visit[y][x]){
			visit[y][x] = 0;
			if (temp_map[y][x] == 0){
				temp_map[y][x] = cnt;
			}

			if (y > 0 && map[y - 1][x] == 1 && visit[y - 1][x] == 1){
				temp.x = x;
				temp.y = y - 1;
				temp.cnt = cnt + 1;
				my_queue.push(temp);
			}
			if (map[y + 1][x] == 1 && visit[y + 1][x] == 1){
				temp.x = x;
				temp.y = y + 1;
				temp.cnt = cnt + 1;
				my_queue.push(temp);
			}

			if (x > 0 && map[y][x - 1] == 1 && visit[y][x - 1] == 1){
				temp.x = x - 1;
				temp.y = y;
				temp.cnt = cnt + 1;
				my_queue.push(temp);
			}

			if (map[y][x + 1] == 1 && visit[y][x + 1] == 1){
				temp.x = x + 1;
				temp.y = y;
				temp.cnt = cnt + 1;
				my_queue.push(temp);
			}
		}
	}
	if (check_cnt < cnt){
		check_cnt = cnt;
	}
}

int main(){

	cin >> H >> W;

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			char temp;
			cin >> temp;
			if (temp == 'W') map[i][j] = 0;
			if (temp == 'L') map[i][j] = 1;
		}
	}

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			if (map[i][j] == 1) bfs(j, i);
		}
	}
	cout << check_cnt << endl;
	return 0;
}
#endif

/*

#include <iostream>

using namespace std;

int map[51][51];
int H, W;
int n, cnt;
int x[2500], y[2500], i[2500];
int check = 0;
int move_time = 0;
bool Top, Bottom, Left, Right;
void enqueue(int _x, int _y, int _i){
	x[cnt] = _x;
	y[cnt] = _y;
	i[cnt] = _i;
	cnt++;
}

void bfs(int _x, int _y){
	int pos = 0;
	int temp[51][51];
	for (int k = 0; k < 51; k++){
		for (int j = 0; j < 51; j++){
			temp[k][j] = 1;
		}
	}
	int number[51][51] = { 0, };
	enqueue(_x, _y, 0);

	while (pos < cnt){

		temp[y[pos]][x[pos]] = 0;
		if (number[y[pos]][x[pos]] == 0) number[y[pos]][x[pos]]= i[pos];
		if (number[y[pos]][x[pos]] > i[pos]) number[y[pos]][x[pos]] = i[pos];

		if (y[pos] > 0 && map[y[pos] - 1][x[pos]] == 1 && temp[y[pos] - 1][x[pos]] != 0){
			enqueue(x[pos], y[pos] - 1, i[pos] + 1);
			Top = true;
		}
		else Top = false;
		if (map[y[pos] + 1][x[pos]] == 1 && temp[y[pos] + 1][x[pos]] != 0){
			enqueue(x[pos], y[pos] + 1, i[pos] + 1);
			Bottom = true;
		}
		else Bottom = false;
		if (x[pos] > 0 && map[y[pos]][x[pos] - 1] == 1 && temp[y[pos]][x[pos]-1] != 0){
			enqueue(x[pos] - 1, y[pos], i[pos] + 1);
			Left = true;
		}
		else Left = false;
		if (map[y[pos]][x[pos] + 1] == 1 && temp[y[pos]][x[pos] +1] != 0){
			enqueue(x[pos] + 1, y[pos], i[pos] + 1);
			Right = true;
		}
		else Right = false;

		if (!Top && !Bottom && !Left && !Right){
			if (check < number[y[pos]][x[pos]]) check = number[y[pos]][x[pos]];
		}

		pos++;
	}

	//if (pos <= cnt) cout << i[pos] << endl;
	//cout << check << endl;
	if (move_time < check) move_time = check;

	cnt = 0;
}

int main(){

	cin >> H >> W;

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			char temp;
			cin >> temp;
			if (temp == 'W') map[i][j] = 0;
			if (temp == 'L') map[i][j] = 1;
		}
	}

	for(int k = 0; k < H; k++){
		for (int j = 0; j < W; j++){
			if (map[k][j] == 1) bfs(j, k);
		}
	}

	cout << move_time << endl;

	return 0;
}

*/