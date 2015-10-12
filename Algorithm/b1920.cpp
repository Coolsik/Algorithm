#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int  A[100001];
int  B[100001];

int compare(const void *a, const void *b) {

	if (*(int*)a <  *(int*)b) return -1;
	if (*(int*)a == *(int*)b) return  0;

	return 1;
}
int vector_compare(void a, void b){
	if (a < b){
		return -1;
	}
	if (a == b) return 0;

	return 1;
}
int main(){
	int nothing = -1;
	int N, M;

	vector<int> arr;
	cin >> N;
	

	for (int i = 0; i < N; i++){
		//cin >> A[i];
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}


	cin >> M;

	for (int i = 0; i < M; i++){
		cin >> B[i];
	}
	//qsort(A, N, sizeof(A[0]), compare);
	sort(arr.begin(), arr.end());
	//qsort(B, M, sizeof(B[0]), compare);
	for (int i = 0; i < M; i++){

		bool find = binary_search(arr.begin(), arr.end(), B[i]);
		if (find == true){
			cout << "1" << endl;
		}
		else{
			cout << "0" << endl;
		}
	//bool find = binary_search(A, A+N, B[i]);

	}

	return 0;
}


#if 0

#include <iostream>
#include <algorithm>

using namespace std;

int  A[100001];
int  B[100001];

int compare(const void *a, const void *b) {

	if (*(int*)a <  *(int*)b) return -1;
	if (*(int*)a == *(int*)b) return  0;

	return 1;
}

int main(){
	int nothing = -1;
	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> A[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++){
		cin >> B[i];
	}
	qsort(A, N, sizeof(A[0]), compare);
	qsort(B, M, sizeof(B[0]), compare);
	
	int j = 0;

	for (int i = 0; i < M; i++){
		if (N == j){
			cout << "0" << endl;
		}
		else if (B[i] == A[j]){
			cout << "1" << endl;
			j++;
		}
		else if (B[i]>A[j]){
			i--;
			j++;
		}
		else if (B[i] < A[j]){
			cout << "0" << endl;
		}
	}

	return 0;
}

#endif