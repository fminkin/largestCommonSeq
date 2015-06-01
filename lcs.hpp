#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const long long INF = 10000000;
using namespace std;


vector <vector<bool>> get_critical_points(string &main_string, string &sub_string) {
  
    vector <vector <bool>> result(sub_string.size() + 1, vector<bool>(sub_string.size() + 1, 0));
    vector <vector <int>> horisontal(main_string.size() + 1, vector<int>(sub_string.size() + 1, 0)), vertical(main_string.size() + 1, vector<int>(sub_string.size() + 1, 0));
    
    for (size_t i = 0; i <= sub_string.size(); ++i) {

	horisontal[0][i] = i;
    }
    for (size_t i = 1; i <= main_string.size(); ++i) {
	for (size_t j = 1; j <= sub_string.size(); ++j) {
	    if (main_string[i - 1] == sub_string[j - 1]) {
		horisontal[i][j] = vertical[i][j - 1];
		vertical[i][j] = horisontal[i - 1][j];
	    } else {
		horisontal[i][j] = max(horisontal[i - 1][j], vertical[i][j - 1]);
		vertical[i][j] = min(horisontal[i - 1][j], vertical[i][j - 1]);
	    }
	}
    }
    
    for (size_t i = 1; i <= sub_string.size(); ++i) {
	if (horisontal[main_string.size()][i]) {
	    result[horisontal[main_string.size()][i] - 1][i] = 1;
	}
    }
    return result;
}

vector <vector <int>> get_lcs_square(string &main_string, string &sub_string) {
  
    vector <vector <bool>> critical_points = get_critical_points(main_string, sub_string);
    vector <vector <int>> result(critical_points.size(), vector<int>(critical_points.size(), 0));

    for (size_t j = 1; j < result.size(); ++j) {
	for (size_t i = 0; i < result.size() - j; ++i) { 
	    size_t curY = i;
	    size_t curX = i + j;
	    if (result[curY][curX - 1] != result[curY + 1][curX]) {
		result[curY][curX] = max(result[curY][curX - 1], result[curY + 1][curX]);
	    } else {
	    if (j == 1 || result[curY + 1][curX - 1] != result[curY + 1][curX]) {
		result[curY][curX] = result[curY + 1][curX] + 1 - critical_points[curY][curX];
	    } else {
		result[curY][curX] = result[curY + 1][curX];
	    }
	    }
	}
    }
    return result;
}



vector <vector <int> > get_lcs_cube(string &main_string, string &sub_string) {
  
    vector <vector <int>> result(sub_string.size() + 1, vector<int>(sub_string.size()+1, 0)), dynamics(main_string.size() + 1, vector<int>(sub_string.size()+1, 0));
    result.resize(sub_string.size() + 1);

    for (size_t i = 1; i <= sub_string.size(); ++i) {
        for (size_t j = 0; j < dynamics.size(); ++j) {
        for (size_t k = 0; k < dynamics[j].size(); ++k) {
                dynamics[j][k] = 0;
            }
        }
        for (size_t j = 1; j <= main_string.size(); ++j) {
            for (size_t k = i; k <= sub_string.size(); ++k) {
                dynamics[j][k] = max(dynamics[j - 1][k], dynamics[j][k - 1]);
                if (main_string[j - 1] == sub_string[k - 1]) {
                    dynamics[j][k] = max(dynamics[j][k], dynamics[j - 1][k - 1] + 1);
                }
            }
        }
        for (size_t j = i; j <= sub_string.size(); ++j) {
            result[i - 1][j] = dynamics[main_string.size()][j];
        }
    }
    return result;
}
