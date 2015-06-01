#include <iostream>
#include "tests.h"


int main() {
	int mainStringSize, subseqStringSize, testSize;
	cin >> mainStringSize >> subseqStringSize >> testSize;
	cout << (proceedTest(mainStringSize, subseqStringSize, testSize) ? "OK\n" : "WRONG\n");
	system("pause");
	return 0;
}
