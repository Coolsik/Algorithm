#include <iostream>

using namespace std;

int d[31];	// d[i] => i까지 오르는 경우의 수
			// 처음에 1칸 오르는 경우 d[i-1]
			// 처음에 2칸 오르는 경우 d[i-2];
			// d[i] = d[i-1] + d[i-2];


template<int N> struct func {
	static inline int fill(int arr[]) {
		return arr[N] = func<N - 1>::fill(arr) + func<N - 2>::fill(arr);
	}
};
template<> struct func<1> {
	static inline int fill(int arr[]) {return 1;}
};
template<> struct func<0> {
	static inline int fill(int arr[]) {return 0;}
};

int main() {
	int N;
	cin >> N;

	func<31>::fill(d);
	cout << d[N+1];

	return 0;
}
