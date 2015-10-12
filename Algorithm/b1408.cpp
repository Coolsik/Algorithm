#include <iostream>
#include <string>
using namespace std;

int main() {
	int nh, nm, ns, sh, sm, ss, rh, rm, rs;
	int carry = 0;

	scanf("%d:%d:%d", &nh, &nm, &ns);
	scanf("%d:%d:%d", &sh, &sm, &ss);

	if (ss >= ns) {
		rs = ss - ns;
	}
	else {
		carry = 1;
		rs = 60 + ss - ns;
	}

	if (sm >= nm + carry) {
		rm = sm - (nm + carry);
		carry = 0;
	}
	else {
		rm = 60 + sm - (nm + carry);
		carry = 1;
	}

	if (sh >= nh + carry) {
		rh = sh - (nh + carry);
		carry = 0;
	}
	else {
		rh = 24 + sh - (nh + carry);
	}

	printf("%02d:%02d:%02d\n", rh, rm, rs);
	return 0;
}