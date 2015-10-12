#include <iostream>
#include <string>

using namespace std;

int main(){
	string A, B;
	char temp[100];
	int sum=0, index=0;
	while (1){
		cin >> A;
		if (cin.eof()){
			break;
		}
		B.append(A);
	}

	for (int i = 0; i < B.length(); i++){
		if (B.at(i) != ','){
			temp[index++] = B.at(i);
		}
		if(B.at(i) ==',' || B.length()-1 == i){
			temp[index++] = '\0';
			index = 0;
			sum += atoi(temp);
		}
	}
	cout << sum << endl;
	return 0;
}