#include <iostream>
#include <string>
using namespace std;
int main(){
	int cnt;
	cin >> cnt;
	string str;
	cin >> str;
	int A = 0, B = 0;
	for (int i = 0; i < cnt; i++){
		if ('A' == str[i]) A++;
		if ('B' == str[i]) B++;
	}
	if (A == B) cout << "Tie" << endl;
	if (A > B) cout << "A" << endl;
	if (A < B) cout << "B" << endl;
}