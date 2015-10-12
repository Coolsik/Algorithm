#include <iostream>

using namespace std;

int main(){

	int K, N, M, result;

	cin >> K >> N >> M;

	if ((result = (K*N) - M) > 0){
		cout << (K*N) - M << endl;
	}
	else
		cout << "0" << endl;

	

	return 0;
}