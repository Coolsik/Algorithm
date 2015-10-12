/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		int N;
		cin >> N;

		string temp[10];
		for (int i = 0; i < N; i++){
			cin >> temp[i];
		}

		sort(temp, temp + N);

		cout << "#testcase" << (itr + 1) << endl;
		for (int i = 0; i < N; i++){
			cout << temp[i]<<endl;
		}
		/*

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}


#if 0

/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
int arr[100000] = { 0 };
int fa[100000][3] = { 0 };
int max(int a, int b){
	if (a<b)return b;
	else return a;
}

int f(int n, int i){
	if (fa[n][i] != -1)return fa[n][i];
	if (n == 1 && i == 0){
		return fa[n][i] = 0;
	}
	else if (n == 1 && i == 1){
		return fa[n][i] = arr[1];
	}
	else if (n == 1 && i == 2){
		return fa[n][i] = -2000000000;
	}
	else{
		if (i == 0){
			return fa[n][i] = max(f(n - 1, 2), max(f(n - 1, 1), f(n - 1, 0)));
		}
		else if (i == 1){
			return fa[n][i] = f(n - 1, 0) + arr[n];
		}
		else{
			return fa[n][i] = f(n - 1, 1) + arr[n];
		}
	}
}

int main()
{

	int nCount;      /* 문제의 테스트 케이스 */

	cin >> nCount;   /* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		for (int i = 0; i<100000; i++){
			fa[i][0] = fa[i][1] = fa[i][2] = -1;
		}
		cout << "#testcase" << (itr + 1) << endl;

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		cout << max(f(n, 0), max(f(n, 1), f(n, 2))) << endl;

		for (int i = 0; i <= n; i++){
			arr[i] = 0;
		}
	}

	return 0;   /* 반드시 return 0으로 해주셔야합니다. */

}

#endif