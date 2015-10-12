#include <iostream>

using namespace std;
int N, L, cur;

int main(){
	cin >> N >> L;
	int len, dir;
	int old_len, old_dir;
	int result = 0;
	cin >> old_len >> old_dir;

	for (int i = 0; i < N - 1; i++){
		cin >> len >> dir;

		if (old_dir != dir){
			if (result < (L - len - old_len) / 2){
				result = (L - len - old_len) / 2;
			}
		}
		old_len = len; old_dir = dir;
	}

	cout << result << endl;

	return 0;
}

#if 0

#include <iostream>
#include <algorithm>

using namespace std;
int N, L,cur;

int main(){
	cin >> N >> L;
	int len, dir;
	int old_len, old_dir;
	int result = 0;
	cin >> old_len >> old_dir;

	for (int i = 0; i < N-1; i++){
		cin >> len >> dir;

		if (old_dir != dir && len<L/2 && old_len<L/2){
			if (result < abs((len - (L - old_len)) / 2)){
				result = abs((len - (L - old_len)) / 2);
			}
		}
		old_len = len; old_dir = dir;
	}

	cout << result << endl;

	return 0;
}
#endif

#if 0

#include <iostream>
#include <queue>
using namespace std;

int main(){
	int N, L;
	queue<pair<int, int> > stick;
	pair<int, int> temp;

	cin >> N >> L;

	for (int i = 0; i < N; i++){
		cin >> temp.first >> temp.second;
		stick.push(temp);
	}

	int time = 0;

	int now_length, now_dir, now_loc;
	int next_loc, next_length;
	now_length = stick.front().first;
	now_dir = stick.front().second;
	stick.pop();
	int func;
	while (stick.size() != 0){
		next_length = stick.front().first;
		if (now_length != L){
			func = time % ((L - now_length) * 2);

			if (func < L - now_length){
				if (now_dir == 0) now_loc = func;
				else now_loc = (L - now_length) - func;
			}
			else{
				if (now_dir == 0) now_loc = (now_length * 2) - func;
				else now_loc = func - (L - now_length);
			}
		}
		else
			now_loc = 0;

		if (next_length != L){
			func = time % ((L - next_length) * 2);

			if (func < L - next_length){
				if (stick.front().second == 0) next_loc = func;
				else next_loc = (L - next_length) - func;
			}
			else{
				if (stick.front().second == 0) next_loc = (next_length * 2) - func;
				else next_loc = func - (L - next_length);
			}
		}
		else
			next_loc = 0;
		if (now_loc <= next_loc && now_loc + now_length >= next_loc || now_loc <= next_loc + next_length && now_loc + now_length >= next_loc + next_length
			|| next_loc <= now_loc && next_loc+next_length>now_loc || next_loc <= now_loc+now_length && next_loc+next_length > now_loc+now_length ){
			now_length = stick.front().first;
			now_dir = stick.front().second;
			stick.pop();
		}
		else{
			time++;
		}

	}

	cout << time << endl;

	return 0;
}

#endif