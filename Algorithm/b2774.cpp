#include <iostream>
#include <string>
using namespace std;

int main(){
	int size, testcase;
	
	cin >> testcase;
	while (testcase-- > 0){
		bool check[11] = { false, };
		string num;
		cin >> num;

		size = num.size();

		for (int i = 0; i < size; i++){
			check[num[i] - 48] = true;
		}
		int count = 0;
		for (int i = 0; i < 11; i++){
			if (check[i]) count++;
		}
		cout << count << endl;
	}
	return 0;
}