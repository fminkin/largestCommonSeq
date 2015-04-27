#pragma once

#include "lcs.h"
#include <random>
#include <algorithm>

default_random_engine generator;

int generateRandom(int minX, int maxX)
{
	std::uniform_int_distribution<int> distribution(minX, maxX);
	return distribution(generator);
}

string generateString(size_t size) {
	string result = "";
	for (size_t i = 0; i < size; ++i) {
		result += char(generateRandom(0, 25) + 'a');
	}
	return result;
}

bool proceedTest(size_t sizeMain, size_t sizeSubseq, size_t testSize) {
	string mainString = generateString(sizeMain);
	string subseqString = generateString(sizeSubseq);
	int i = 0;
	bool flag = true;
	do {
		flag &= getFastMatrixLCS(mainString, subseqString) == getSlowMatrixLCS(mainString, subseqString);
		i++;
	} while (i < testSize && next_permutation(subseqString.begin(), subseqString.end()));
	return flag;
}

