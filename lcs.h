#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const long long INF = 10000000;
using namespace std;


vector <vector<bool>> getCriticalPoints(string &mainString, string &subseqString) {
	vector <vector <bool>> result;
	vector <vector <int>> horisontalDynamics, verticalDynamics;

	result.resize(subseqString.size() + 1);
	horisontalDynamics.resize(mainString.size() + 1);
	verticalDynamics.resize(mainString.size() + 1);

	for (size_t i = 0; i <= subseqString.size(); ++i) {
		result[i].resize(subseqString.size() + 1, 0);
	}

	for (size_t i = 0; i <= mainString.size(); ++i) {
		horisontalDynamics[i].resize(subseqString.size() + 1, 0);
		verticalDynamics[i].resize(subseqString.size() + 1, 0);
	}

	for (size_t i = 0; i <= subseqString.size(); ++i) {
		horisontalDynamics[0][i] = i;
	}

	for (size_t i = 0; i <= mainString.size(); ++i) {
		verticalDynamics[i][0] = 0;
	}

	for (size_t i = 1; i <= mainString.size(); ++i) {
		for (size_t j = 1; j <= subseqString.size(); ++j) {
			if (mainString[i - 1] == subseqString[j - 1]) {
				horisontalDynamics[i][j] = verticalDynamics[i][j - 1];
				verticalDynamics[i][j] = horisontalDynamics[i - 1][j];
			} else {
				horisontalDynamics[i][j] = max(horisontalDynamics[i - 1][j], verticalDynamics[i][j - 1]);
				verticalDynamics[i][j] = min(horisontalDynamics[i - 1][j], verticalDynamics[i][j - 1]);
			}
		}
	}

	for (size_t i = 1; i <= subseqString.size(); ++i) {
		if (horisontalDynamics[mainString.size()][i]) {
			result[horisontalDynamics[mainString.size()][i] - 1][i] = 1;
		}
	}

	return result;
}

vector <vector <int>> getFastMatrixLCS(string &mainString, string &subseqString) {
	vector <vector <int>> result;
	vector <vector <bool>> criticalPoints = getCriticalPoints(mainString, subseqString);

	result.resize(criticalPoints.size());

	for (size_t i = 0; i < result.size(); ++i) {
		result[i].resize(criticalPoints.size(), 0);
	}

	for (size_t j = 1; j < result.size(); ++j) {
		for (size_t i = 0; i < result.size() - j; ++i) { 
			size_t curX = i;
			size_t curY = i + j;
			if (result[curX][curY - 1] != result[curX + 1][curY]) {
				result[curX][curY] = max(result[curX][curY - 1], result[curX + 1][curY]);
			} else {
				if (j == 1 || result[curX + 1][curY - 1] != result[curX + 1][curY]) {
					result[curX][curY] = result[curX + 1][curY] + 1 - criticalPoints[curX][curY];
				} else {
					result[curX][curY] = result[curX + 1][curY];
				}
			}
		}
	}

	return result;
}



vector <vector <int> > getSlowMatrixLCS(string &mainString, string &subseqString) {
	vector <vector <int>> result, dynamics;
	result.resize(subseqString.size() + 1);

	for (size_t i = 0; i < result.size(); ++i) {
		result[i].resize(subseqString.size() + 1, 0);
	}

	dynamics.resize(mainString.size() + 1);

	for (size_t i = 0; i < dynamics.size(); ++i) {
		dynamics[i].resize(subseqString.size() + 1);
	}

	for (size_t i = 1; i <= subseqString.size(); ++i) {
		for (size_t j = 0; j < dynamics.size(); ++j) {
			for (size_t k = 0; k < dynamics[j].size(); ++k) {
				dynamics[j][k] = 0;
			}
		}
		for (size_t j = 1; j <= mainString.size(); ++j) {
			for (size_t k = i; k <= subseqString.size(); ++k) {
				dynamics[j][k] = max(dynamics[j - 1][k], dynamics[j][k - 1]);
				if (mainString[j - 1] == subseqString[k - 1]) {
					dynamics[j][k] = max(dynamics[j][k], dynamics[j - 1][k - 1] + 1);
				}
			}
		}
		for (size_t j = i; j <= subseqString.size(); ++j) {
			result[i - 1][j] = dynamics[mainString.size()][j];
		}
	}
	return result;
}
