#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char dic[101];
	char orig[101];
	char temp[101];
	int max, orig_count = 0, now_count, sim_dic=0;
	int match;
	cin >> max;
	for (int i = 0; i < max; i++){
		cin >> dic;
		if (i == 0){
			strcpy(orig, dic);
			for (int j = 0; j < 101; j++){
				if (orig[j] == '\0') break;
				orig_count++;
			}
		}
		else{
			now_count = 0;
			match = 0;
			for (int j = 0; j < 101; j++){
				if (dic[j] == '\0') break;
				now_count++;
			}
			if (now_count < orig_count - 1 || now_count > orig_count + 1){
				continue;
			}
			//if (orig_count == now_count){
			else{
				strcpy(temp, orig);
				
				for (int ori = 0; ori < orig_count; ori++){
					for (int now = 0; now < now_count; now++){
						if (temp[ori] == dic[now])
						{
							temp[ori] = '0';
							dic[now] = '0';
							match++;
							break;
						}
					}
				}
				if (orig_count == now_count || orig_count > now_count){
					if (match >= orig_count - 1){
						sim_dic++;
						continue;
					}
				}
				else{
					if (match == orig_count){
						sim_dic++;
						continue;
					}
				}
			}

		}
	}

	cout << sim_dic << endl;

	return 0;
}

