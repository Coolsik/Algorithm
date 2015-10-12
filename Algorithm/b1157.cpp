#include <iostream>
#include <string>
using namespace std;
int check[26];
int main(){
	string temp;
	cin >> temp;
	int size = temp.size();
	for (int i = 0; i < size; i++){
		if (temp[i] == 'a' || temp[i] == 'A') check[0]++;
		if (temp[i] == 'b' || temp[i] == 'B') check[1]++;
		if (temp[i] == 'c' || temp[i] == 'C') check[2]++;
		if (temp[i] == 'd' || temp[i] == 'D') check[3]++;
		if (temp[i] == 'e' || temp[i] == 'E') check[4]++;
		if (temp[i] == 'f' || temp[i] == 'F') check[5]++;
		if (temp[i] == 'g' || temp[i] == 'G') check[6]++;
		if (temp[i] == 'h' || temp[i] == 'H') check[7]++;
		if (temp[i] == 'i' || temp[i] == 'I') check[8]++;
		if (temp[i] == 'j' || temp[i] == 'J') check[9]++;
		if (temp[i] == 'k' || temp[i] == 'K') check[10]++;
		if (temp[i] == 'l' || temp[i] == 'L') check[11]++;
		if (temp[i] == 'm' || temp[i] == 'M') check[12]++;
		if (temp[i] == 'n' || temp[i] == 'N') check[13]++;
		if (temp[i] == 'o' || temp[i] == 'O') check[14]++;
		if (temp[i] == 'p' || temp[i] == 'P') check[15]++;
		if (temp[i] == 'q' || temp[i] == 'Q') check[16]++;
		if (temp[i] == 'r' || temp[i] == 'R') check[17]++;
		if (temp[i] == 's' || temp[i] == 'S') check[18]++;
		if (temp[i] == 't' || temp[i] == 'T') check[19]++;
		if (temp[i] == 'u' || temp[i] == 'U') check[20]++;
		if (temp[i] == 'v' || temp[i] == 'V') check[21]++;
		if (temp[i] == 'w' || temp[i] == 'W') check[22]++;
		if (temp[i] == 'x' || temp[i] == 'X') check[23]++;
		if (temp[i] == 'y' || temp[i] == 'Y') check[24]++;
		if (temp[i] == 'z' || temp[i] == 'Z') check[25]++;
	}
	int maxvalue = 0; bool same = false; char saveword;
	for (int i = 0; i < 26; i++){
		if (maxvalue == check[i]){
			same = true;
		}
		if (maxvalue < check[i]){
			maxvalue = check[i];
			saveword = i+65;
			same = false;
		}
	}

	if (same){
		cout << "?" << endl;
	}
	else{
		cout << saveword << endl;
	}

	return 0;
}