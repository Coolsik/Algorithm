#include <iostream>

using namespace std;

int main(){
	int testcase;

	cin >> testcase;

	while (testcase-- > 0){
		int s;
		cin >> s;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			int A, B;
			cin >> A >> B;
			s += A*B;
		}
		cout << s << endl;
	}
	return 0;
}