//
//  main.cpp
//  all_substr_common_subseq
//
//  Created by Даня on 27.04.15.
//  Copyright (c) 2015 mipt. All rights reserved.
//

#include <iostream>
#include "tests.h"


int main() {
	int mainStringSize, subseqStringSize, testSize;
	cin >> mainStringSize >> subseqStringSize >> testSize;
	cout << (proceedTest(mainStringSize, subseqStringSize, testSize) ? "OK\n" : "WRONG\n");
	system("pause");
	return 0;
}
